/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_create_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 02:12:27 by tristan           #+#    #+#             */
/*   Updated: 2018/04/07 19:24:36 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_vec_create_list(t_vector **list, int nb_elem)
{
	int			i;

	i = 0;
	while (i <= nb_elem)
	{
		ft_vec_add(list);
		i++;
	}
}
