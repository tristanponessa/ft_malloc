/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_elem_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:50:04 by tristan           #+#    #+#             */
/*   Updated: 2018/07/22 19:19:41 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_vec_elem_del(t_vector **list)
{
	if (!(*list))
		return ;
	ft_vec_to_limit(list, "b");
	while ((*list)->next->next)
		(*list) = (*list)->next;
	free((*list)->next);
	(*list)->next = NULL;
}
