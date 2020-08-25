/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 02:04:58 by tristan           #+#    #+#             */
/*   Updated: 2018/03/30 18:00:52 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_for(int nb_of_times, char *version)
{
	static int		counter[1000];
	static int		i;
	int 			v;

	if (ft_strcmp(version,"reset") == 0)
		ft_memset(counter, 0, 1000);
	v = ft_atoi(version);
	if (i <= nb_of_times)
		counter[v]++;
	if (i > nb_of_times)
	{
		counter[v] = 0;
		return (0);
	}
	return (1);
}
