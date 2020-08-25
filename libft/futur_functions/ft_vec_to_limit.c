/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_to_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:49:50 by trponess          #+#    #+#             */
/*   Updated: 2018/07/22 19:19:41 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_vec_to_limit(t_vector **list, char *limit)
{
	int step;
	
	if (!limit)
		ft_printf("char *limit : you put an int not a char*\n");
	step = 0;
	while ((*list)->last)
	{
		*list = (*list)->last;
		step++;
	}
	while ((*list)->pos != ft_atoi(limit) && ft_strcmp(limit, "e") != 0)
	{
		step = 0;
		*list = (*list)->next;
		step++;
	}
	if (ft_strcmp(limit, "e") == 0)
	{
		while ((*list)->next)
		{
			*list = (*list)->next;
			step++;
		}
	}
	return (step);
}
