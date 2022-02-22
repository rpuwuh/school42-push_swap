/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advancedaction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:05:53 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/20 20:44:53 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrandra(t_env *env, unsigned int n1, unsigned int n2)
{
	size_t	i;

	if (!env || !env->a || !env->b)
		return ;
	i = 0;
	while (i < (size_t) n1)
	{
		ft_rr(env);
		i++;
	}
	i = 0;
	while (i < (size_t) n2)
	{
		ft_ra(env);
		i++;
	}
}

void	ft_rrandrb(t_env *env, unsigned int n1, unsigned int n2)
{
	size_t	i;

	if (!env || !env->a || !env->b)
		return ;
	i = 0;
	while (i < (size_t) n1)
	{
		ft_rr(env);
		i++;
	}
	i = 0;
	while (i < (size_t) n2)
	{
		ft_rb(env);
		i++;
	}
}

void	ft_rrrandrra(t_env *env, unsigned int n1, unsigned int n2)
{
	size_t	i;

	if (!env || !env->a || !env->b)
		return ;
	i = 0;
	while (i < (size_t) n1)
	{
		ft_rrr(env);
		i++;
	}
	i = 0;
	while (i < (size_t) n2)
	{
		ft_rra(env);
		i++;
	}
}

void	ft_rrrandrrb(t_env *env, unsigned int n1, unsigned int n2)
{
	size_t	i;

	if (!env || !env->a || !env->b)
		return ;
	i = 0;
	while (i < (size_t) n1)
	{
		ft_rrr(env);
		i++;
	}
	i = 0;
	while (i < (size_t) n2)
	{
		ft_rrb(env);
		i++;
	}
}

void	ft_raandrrb(t_env *env, unsigned int n1, unsigned int n2)
{
	size_t	i;

	if (!env || !env->a || !env->b)
		return ;
	i = 0;
	while (i < (size_t) n1)
	{
		ft_ra(env);
		i++;
	}
	i = 0;
	while (i < (size_t) n2)
	{
		ft_rrb(env);
		i++;
	}
}
