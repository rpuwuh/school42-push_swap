/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choosesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:59:51 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/20 20:53:48 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_findrastacknum(t_stack *a, unsigned int n)
{
	unsigned int	i;

	if (!a)
		return (0);
	i = 0;
	while (a && a->num != n)
	{
		a = a->next;
		i++;
	}
	if (!a || a->num != n)
		return (0);
	return (i);
}

static void	ft_rolllittlestacknum(t_env *env, unsigned int n)
{
	if (ft_findrastacknum(env->a, n) < 3)
		while (env->a->num != n)
			ft_ra(env);
	else
		while (env->a->num != n)
			ft_rra(env);
}

static void	ft_sortafour(t_env *env)
{
	ft_rolllittlestacknum(env, 0);
	if (ft_isstacksorted(env->a))
		return ;
	ft_pb(env);
	ft_sortathree(env);
	ft_pa(env);
}

static void	ft_sortafive(t_env *env)
{
	ft_rolllittlestacknum(env, 0);
	if (ft_isstacksorted(env->a))
		return ;
	ft_pb(env);
	if (ft_isnotstrictlysorted(env->a))
	{
		ft_rolllittlestacknum(env, 1);
		ft_pa(env);
		ft_rolllittlestacknum(env, 0);
		return ;
	}
	ft_rolllittlestacknum(env, 1);
	ft_pb(env);
	ft_sortathree(env);
	ft_pa(env);
	ft_pa(env);
}

void	ft_choosesort(t_env *env)
{
	if (ft_isstacksorted(env->a) || !(env->max))
		(void) env;
	else if (env->max == 1 && !ft_isstacksorted(env->a))
		ft_sa(env);
	else if (env->max == 2)
		ft_sortathree(env);
	else if (env->max == 3)
		ft_sortafour(env);
	else if (env->max == 4)
		ft_sortafive(env);
	else
		ft_middlesort(env);
}
