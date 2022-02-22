/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:00:55 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/14 20:01:16 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_env *env)
{
	t_stack	*tmp;

	if (!env || !(env->a) || !(env->a->next))
		return ;
	tmp = env->a;
	env->a = env->a->next;
	ft_stacklast(env->a)->next = tmp;
	tmp->next = 0;
	env->s = ft_stradd(&(env->s), "ra\n");
}

void	ft_rb(t_env *env)
{
	t_stack	*tmp;

	if (!env || !(env->b) || !(env->b->next))
		return ;
	tmp = env->b;
	env->b = env->b->next;
	ft_stacklast(env->b)->next = tmp;
	tmp->next = 0;
	env->s = ft_stradd(&(env->s), "rb\n");
}

void	ft_rr(t_env *env)
{
	t_stack	*tmp;

	if (!env || !(env->a) || !(env->a->next) || !(env->b) || !(env->b->next))
		return ;
	tmp = env->a;
	env->a = env->a->next;
	ft_stacklast(env->a)->next = tmp;
	tmp->next = 0;
	tmp = env->b;
	env->b = env->b->next;
	ft_stacklast(env->b)->next = tmp;
	tmp->next = 0;
	env->s = ft_stradd(&(env->s), "rr\n");
}
