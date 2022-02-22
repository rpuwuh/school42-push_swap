/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chooseaction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:01:44 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/21 15:25:51 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_doscore(t_env *env)
{
	t_stack	*tmp;

	if (!env || !env->b)
		return ;
	tmp = env->b;
	while (tmp)
	{
		tmp->score = ft_score(env, tmp->num);
		tmp = tmp->next;
	}
}

unsigned int	ft_choosescore(t_env *env)
{
	unsigned int	i;
	t_stack			*tmp;

	if (!env || !env->b)
		return (0);
	i = ~0;
	tmp = env->b;
	while (tmp)
	{
		if (tmp->score < i)
			i = tmp->score;
		tmp = tmp->next;
	}
	return (i);
}

unsigned int	ft_findnumscore(t_env *env, unsigned int score)
{
	t_stack			*tmp;
	unsigned int	i;

	if (!env || !env->b)
		return (0);
	tmp = env->b;
	i = 0;
	while (tmp && tmp->score != score)
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		return (0);
	return (tmp->num);
}

static void	ft_rraandrb(t_env *env, unsigned int n1, unsigned int n2)
{
	size_t	i;

	if (!env || !env->a || !env->b)
		return ;
	i = 0;
	while (i < (size_t) n1)
	{
		ft_rra(env);
		i++;
	}
	i = 0;
	while (i < (size_t) n2)
	{
		ft_rb(env);
		i++;
	}
}

void	ft_chooseaction(t_env *env, unsigned int n, unsigned int score)
{
	if (!env || !env->a || !env->b)
		return ;
	if (score == ft_score_ra(env, n) + ft_score_rrb(env, n))
		ft_raandrrb(env, ft_score_ra(env, n), ft_score_rrb(env, n));
	else if (score == ft_score_rra(env, n) + ft_score_rb(env, n))
		ft_rraandrb(env, ft_score_rra(env, n), ft_score_rb(env, n));
	else if (score == ft_maxuint(ft_score_ra(env, n), ft_score_rb(env, n)))
	{
		if (ft_score_ra(env, n) > ft_score_rb(env, n))
			ft_rrandra(env, ft_score_rb(env, n), ft_score_ra(env, n)
				- ft_score_rb(env, n));
		else
			ft_rrandrb(env, ft_score_ra(env, n), ft_score_rb(env, n)
				- ft_score_ra(env, n));
	}
	else if (score == ft_maxuint(ft_score_rra(env, n), ft_score_rrb(env, n)))
	{
		if (ft_score_rra(env, n) > ft_score_rrb(env, n))
			ft_rrrandrra(env, ft_score_rrb(env, n), ft_score_rra(env, n)
				- ft_score_rrb(env, n));
		else
			ft_rrrandrrb(env, ft_score_rra(env, n), ft_score_rrb(env, n)
				- ft_score_rra(env, n));
	}
}
