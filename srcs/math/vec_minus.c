/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_minus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:34:34 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/17 20:12:15 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_vector	vec_minus(t_vector *a, t_vector *b)
{
    return ((t_vector){a->x - b->x, a->y - b->y, a->z - b->z});
}
