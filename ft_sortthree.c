/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortthree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:18:23 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/15 16:18:42 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_givemeanums(unsigned int *arr, t_env *env)
{
	if (!arr || !env || !(env->a) || !(env->a->next) || !(env->a->next->next))
		return ;
	arr[0] = env->a->num;
	arr[1] = env->a->next->num;
	arr[2] = env->a->next->next->num;
	return ;
}

static	void	ft_givemebnums(unsigned int *arr, t_env *env)
{
	if (!arr || !env || !(env->b) || !(env->b->next) || !(env->b->next->next))
		return ;
	arr[0] = env->b->num;
	arr[1] = env->b->next->num;
	arr[2] = env->b->next->next->num;
	return ;
}

void	ft_sortathree(t_env *env)
{
	unsigned int	arr[3];

	if (!env || !(env->a) || !(env->a->next) || !(env->a->next->next))
		return ;
	if (env->a->next->next->next || ft_isstacksorted(env->a))
		return ;
	ft_givemeanums(arr, env);
	if (arr[0] < arr[1] & arr[1] > arr[2] & arr[0] < arr[2])
	{
		ft_rra(env);
		ft_sa(env);
	}
	else if (arr[0] > arr[1] & arr[1] < arr[2] & arr[0] < arr[2])
		ft_sa(env);
	else if (arr[0] < arr[1] & arr[1] > arr[2] & arr[0] > arr[2])
		ft_rra(env);
	else if (arr[0] > arr[1] & arr[1] < arr[2] & arr[0] > arr[2])
		ft_ra(env);
	else if (arr[0] > arr[1] & arr[1] > arr[2] & arr[0] > arr[2])
	{
		ft_sa(env);
		ft_rra(env);
	}
	return ;
}

void	ft_sortbthree(t_env *env)
{
	unsigned int	arr[3];

	if (!env || !(env->b) || !(env->b->next) || !(env->b->next->next))
		return ;
	if (env->b->next->next->next || ft_isstackrevsorted(env->b))
		return ;
	ft_givemebnums(arr, env);
	if (arr[0] < arr[1] & arr[1] < arr[2] & arr[0] < arr[2])
	{
		ft_rb(env);
		ft_sb(env);
	}
	else if (arr[0] < arr[1] & arr[1] > arr[2] & arr[0] < arr[2])
		ft_rb(env);
	else if (arr[0] > arr[1] & arr[1] < arr[2] & arr[0] < arr[2])
		ft_rrb(env);
	else if (arr[0] < arr[1] & arr[1] > arr[2] & arr[0] > arr[2])
		ft_sb(env);
	else if (arr[0] > arr[1] & arr[1] < arr[2] & arr[0] > arr[2])
	{
		ft_rrb(env);
		ft_sb(env);
	}
	return ;
}
