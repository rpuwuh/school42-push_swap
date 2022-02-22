/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:03:02 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/20 20:37:46 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_minuint(unsigned int n1, unsigned int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

unsigned int	ft_maxuint(unsigned int n1, unsigned int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

unsigned int	ft_score(t_env *env, unsigned int n)
{
	unsigned int	arr[4];

	arr [0] = ft_maxuint(ft_score_ra(env, n), ft_score_rb(env, n));
	arr [1] = ft_maxuint(ft_score_rra(env, n), ft_score_rrb(env, n));
	arr [2] = ft_score_ra(env, n) + ft_score_rrb(env, n);
	arr [3] = ft_score_rra(env, n) + ft_score_rb(env, n);
	arr [0] = ft_minuint(arr[0], arr[1]);
	arr [1] = ft_minuint(arr[2], arr[3]);
	return (ft_minuint(arr[0], arr[1]));
}
