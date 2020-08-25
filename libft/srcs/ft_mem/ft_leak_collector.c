/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leak_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 19:26:14 by trponess          #+#    #+#             */
/*   Updated: 2018/09/22 18:03:10 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void ft_leak_collector(char *data, char *option)
{
	static char *mels[100000];
	static int pos;

	if (ft_strcmp(option, "save") == 0)
	{
		mels[pos] = data;
		pos++;
	}
	if (ft_strcmp(option, "show") == 0)
	{
		int i;

		i = 0;
		while (mels[i][0])
		{
			ft_printf("\nmels[%d]\n : its adress       <%p>\n   poiting to adress :   <%p>\n   content of adress : <%s>\n\n", i, &mels[i], mels[i], mels[i]);
			i++;
		}
	}
	if (ft_strcmp(option, "free") == 0)
	{
		pos--;
		while (pos >= 0)
		{
			if (mels[pos])
				free(mels[pos]);
			mels[pos] = NULL;
			pos--;
		}
	}
}

void ft_leak_dcollector(char **p, char *option)
{
	static char **dmels[100000];
	static int pos;
	
	if (ft_strcmp(option, "save") == 0)
	{
		dmels[pos] = p; 
		pos++;
	}
	if (ft_strcmp(option, "free") == 0)
	{
		pos--;
		while (pos >= 0)
		{
			if (dmels[pos])
				free(dmels[pos]);
			pos--;
		}
	}
}

