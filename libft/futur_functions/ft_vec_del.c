/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:49:47 by tristan           #+#    #+#             */
/*   Updated: 2018/07/22 19:19:41 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_vec_del(t_vector **list)
{
	if (!(*list))
		return ;
	ft_vec_to_limit(list, "e");
	while ((*list)->last)
	{
		(*list) = (*list)->last;
//		free((*list)->next->arr);
		free((*list)->next);
		(*list)->next = NULL;
	}
//	free((*list)->next->arr);
	free((*list)->next);
	(*list)->next = NULL;
//	free((*list)->arr);
	free(*list);
	(*list) = NULL;
}
