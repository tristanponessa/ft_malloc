/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:49:25 by tristan           #+#    #+#             */
/*   Updated: 2018/07/22 19:19:41 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_vector	*ft_vec_create_elem(void)
{
	t_vector	*new;
	int i;

	i = 0;
	if (!(new = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	new->arr = ft_arrnew(VECTOR_SIZE); 
	new->len = 0;
	new->pos = 0;
	while (i++ < 20)
		new->id[i] = '\0'; 
	new->cap = VECTOR_SIZE;
	new->next = NULL;
	new->last = NULL;
	return (new);
}
