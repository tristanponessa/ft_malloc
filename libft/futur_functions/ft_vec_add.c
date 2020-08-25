/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:48:30 by tristan           #+#    #+#             */
/*   Updated: 2018/07/22 19:19:41 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_vec_add(t_vector **vec)
{
	t_vector *elem;

	elem = (t_vector *)malloc(sizeof(t_vector));
	if (!elem)
		return ;
	if (!(*vec))
		*vec = ft_vec_create_elem();
	else
	{
		while ((*vec)->next)
			*vec = (*vec)->next;
		elem = ft_vec_create_elem();
		elem->pos = (*vec)->pos + 1;
		elem->last = (*vec);
		(*vec)->next = elem;
		*vec = (*vec)->next;
	}
}
