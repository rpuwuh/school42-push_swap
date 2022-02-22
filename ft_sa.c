/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:21:30 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/14 19:32:39 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_env *env)
{
	t_stack	*tmp;

	if (!env || !(env->a) || !(env->a->next))
		return ;
	tmp = env->a->next;
	env->a->next = env->a->next->next;
	tmp->next = env->a;
	env->a = tmp;
	env->s = ft_stradd(&(env->s), "sa\n");
}

void	ft_sb(t_env *env)
{
	t_stack	*tmp;

	if (!env || !(env->b) || !(env->b->next))
		return ;
	tmp = env->b->next;
	env->b->next = env->b->next->next;
	tmp->next = env->b;
	env->b = tmp;
	env->s = ft_stradd(&(env->s), "sb\n");
}

void	ft_ss(t_env *env)
{
	t_stack	*tmp;

	if (!env || !(env->a) || !(env->a->next) || !(env->b) || !(env->b->next))
		return ;
	tmp = env->a->next;
	env->a->next = env->a->next->next;
	tmp->next = env->a;
	env->a = tmp;
	tmp = env->b->next;
	env->b->next = env->b->next->next;
	tmp->next = env->b;
	env->b = tmp;
	env->s = ft_stradd(&(env->s), "ss\n");
}
