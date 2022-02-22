/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:52:35 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/14 19:52:46 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_env *env)
{
	t_stack	*tmp;

	if (!env || !(env->b))
		return ;
	tmp = env->b->next;
	env->b->next = env->a;
	env->a = env->b;
	env->b = tmp;
	env->s = ft_stradd(&(env->s), "pa\n");
}

void	ft_pb(t_env *env)
{
	t_stack	*tmp;

	if (!env || !(env->a))
		return ;
	tmp = env->a->next;
	env->a->next = env->b;
	env->b = env->a;
	env->a = tmp;
	env->s = ft_stradd(&(env->s), "pb\n");
}
