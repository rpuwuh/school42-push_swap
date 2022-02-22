/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstacksorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:41:31 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/15 16:03:58 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isstacksorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_isstackrevsorted(t_stack *b)
{
	if (!b || !b->next)
		return (1);
	while (b->next)
	{
		if (b->num < b->next->num)
			return (0);
		b = b->next;
	}
	return (1);
}
