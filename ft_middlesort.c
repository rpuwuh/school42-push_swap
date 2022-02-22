/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middlesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:43:10 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/22 18:44:30 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rollstacknum(t_env *env, t_stack **st, unsigned int n)
{
	if (!env || !st || !*st || (*st)->num == n)
		return ;
	if (ft_findrastacknum(*st, n)
		&& ft_findrastacknum(*st, n) < ft_stackcount(*st) / 2)
	{
		while ((*st)->num != n)
		{
			if (*st == env->a)
				ft_ra(env);
			if (*st == env->b)
				ft_rb(env);
		}
	}
	else
	{
		while ((*st)->num != n)
		{
			if (*st == env->a)
				ft_rra(env);
			if (*st == env->b)
				ft_rrb(env);
		}
	}
}

void	ft_firstpush(t_env *env)
{
	if (!env || !env->a)
		return ;
	while (ft_stackcount(env->a) > 3)
	{
		if (env->a->num && env->a->num != env->mid && env->a->num != env->max)
		{
			ft_pb(env);
			if (env->b->num < env->mid)
				ft_rb(env);
		}
		else
			ft_ra(env);
	}
}

void	ft_middlesort(t_env *env)
{
	unsigned int	i;

	if (ft_isnotstrictlysorted(env->a))
	{
		ft_rollstacknum(env, &env->a, 0);
		return ;
	}
	ft_firstpush(env);
	ft_sortathree(env);
	while (env->b)
	{
		ft_doscore (env);
		i = ft_findnumscore(env, ft_choosescore(env));
		ft_chooseaction(env, i, ft_choosescore(env));
		ft_pa(env);
	}
	ft_rollstacknum(env, &env->a, 0);
}
