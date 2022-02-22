/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:16:52 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/22 22:44:38 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int	ft_dosa(t_env *env, char *s)
{
	if (s[1] == 'a')
		ft_sa(env);
	else if (s[1] == 'b')
		ft_sb(env);
	else if (s[1] == 's')
	{
		ft_sa(env);
		ft_sb(env);
	}
	else
		return (0);
	return (1);
}

int	ft_dopa(t_env *env, char *s)
{
	if (s[1] == 'a')
		ft_pa(env);
	else if (s[1] == 'b')
		ft_pb(env);
	else
		return (0);
	return (1);
}

int	ft_dorra(t_env *env, char *s)
{
	if (s[2] == 'a')
		ft_rra(env);
	else if (s[2] == 'b')
		ft_rrb(env);
	else if (s[2] == 'r')
	{
		ft_rra(env);
		ft_rrb(env);
	}
	else
		return (0);
	return (1);
}

int	ft_dora(t_env *env, char *s)
{
	if (s[1] == 'a')
		ft_ra(env);
	else if (s[1] == 'b')
		ft_rb(env);
	else if (s[1] == 'r')
	{
		ft_ra(env);
		ft_rb(env);
	}
	else
		return (0);
	return (1);
}

int	ft_doactions(t_env *env, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 's' && ft_dosa(env, s + i))
			i += 2;
		else if (s[i] == 'p' && ft_dopa(env, s + i))
			i += 2;
		else if (s[i] == 'r' && s[i + 1] == 'r' && ft_dorra(env, s + i))
			i += 3;
		else if (s[i] == 'r' && ft_dora(env, s + i))
			i += 2;
		else if (s[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}
