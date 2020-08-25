/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:50:22 by tristan           #+#    #+#             */
/*   Updated: 2018/07/22 19:19:41 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_vec_len(t_vector *list)
{
	ft_vec_to_limit(&list, "e");
	return (list->pos);
}