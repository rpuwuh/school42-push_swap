/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotstrictlysorted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:46:16 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/17 18:43:38 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	ft_stackmin(t_stack *a)
{
	unsigned int	i;

	i = ~0;
	while (a)
	{
		if (a->num < i)
			i = a->num;
		a = a->next;
	}
	return (i);
}

int	ft_isnotstrictlysorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a || !(a->next) || !(a->next->next))
		return (1);
	tmp = a;
	while (tmp->num != ft_stackmin(a))
		tmp = tmp -> next;
	while (tmp -> next)
	{
		if (tmp->num + 1 != tmp->next->num)
			return (0);
		tmp = tmp -> next;
	}
	if (a->num != ft_stackmin(a) && tmp->num + 1 != a->num)
		return (0);
	while (a->num != ft_stackmin(a) && a->next->num != ft_stackmin(a))
	{
		if (a->num + 1 != a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_isnotstrictlyrevsorted(t_stack *a, t_env *env)
{
	t_stack	*tmp;

	if (!a || !(a->next) || !(a->next->next))
		return (1);
	tmp = a;
	while (tmp->num != env->max)
		tmp = tmp -> next;
	while (tmp -> next)
	{
		if (tmp->num - 1 != tmp->next->num)
			return (0);
		tmp = tmp -> next;
	}
	if (a->num != env->max && tmp->num - 1 != a->num)
		return (0);
	while (a->num != env->max && a->next->num != env->max)
	{
		if (a->num - 1 != a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}
