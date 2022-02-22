/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:28:04 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/14 20:28:16 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_env *env)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!env || !(env->a) || !(env->a->next))
		return ;
	tmp1 = env->a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = env->a;
	env->a = tmp2;
	env->s = ft_stradd(&(env->s), "rra\n");
}

void	ft_rrb(t_env *env)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!env || !(env->b) || !(env->b->next))
		return ;
	tmp1 = env->b;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = env->b;
	env->b = tmp2;
	env->s = ft_stradd(&(env->s), "rrb\n");
}

void	ft_rrr(t_env *env)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!env || !(env->a) || !(env->a->next) || !(env->b) || !(env->b->next))
		return ;
	tmp1 = env->a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = env->a;
	env->a = tmp2;
	tmp1 = env->b;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = env->b;
	env->b = tmp2;
	env->s = ft_stradd(&(env->s), "rrr\n");
}
