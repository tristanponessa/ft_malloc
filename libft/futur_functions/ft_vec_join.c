/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:44:51 by tristan           #+#    #+#             */
/*   Updated: 2018/07/22 19:19:41 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_vector	*ft_vec_join(t_vector *v1, t_vector *v2)
{
	t_vector *vec_fusion1;
	t_vector *vec_fusion2;

	vec_fusion1 = v1;
	vec_fusion2 = v2;
	ft_vec_to_limit(&vec_fusion1, "e");
	ft_vec_to_limit(&vec_fusion2, "0");
	vec_fusion1->next = vec_fusion2;
	vec_fusion2->last = vec_fusion1;
	return (vec_fusion1);
}