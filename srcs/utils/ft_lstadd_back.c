/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:55:30 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/09 18:55:33 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstaddback(t_objs **alst, t_objs *new)
{
	t_objs *ptr;

	if (alst && (*alst)->polym)
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else if(*alst)
	{
		*alst = new;
		(*alst)->next = NULL;
	}
}