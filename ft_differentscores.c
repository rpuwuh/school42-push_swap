/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_differentscores.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:58:42 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/21 15:11:45 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	ft_findclosestelem(t_stack *a, unsigned int n)
{
	unsigned int	i;

	if (!a)
		return (0);
	i = (unsigned int) ~0;
	while (a)
	{
		if (a->num > n && a->num < i)
			i = a->num;
		a = a->next;
	}
	if (i == (unsigned int) ~0)
		return (0);
	return (i);
}

unsigned int	ft_score_rb(t_env *env, unsigned int n)
{
	unsigned int	i;
	t_stack			*tmp;

	if (!env)
		return (0);
	tmp = env->b;
	i = 0;
	while (tmp && tmp->num != n)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}

unsigned int	ft_score_ra(t_env *env, unsigned int n)
{
	unsigned int	i;
	t_stack			*tmp;

	if (!env)
		return (0);
	tmp = env->a;
	n = ft_findclosestelem(env->a, n);
	i = 0;
	while (tmp && tmp->num != n)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}

unsigned int	ft_score_rrb(t_env *env, unsigned int n)
{
	if (!env)
		return (0);
	return (ft_stackcount(env->b) - ft_score_rb(env, n));
}

unsigned int	ft_score_rra(t_env *env, unsigned int n)
{
	if (!env)
		return (0);
	return (ft_stackcount(env->a) - ft_score_ra(env, n));
}
