/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initailize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:39:16 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/18 19:29:53 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_env	*ft_initailize(int argc, char **argv)
{
	t_env			*env;
	unsigned int	i;

	env = (t_env *) malloc (sizeof(t_env));
	if (!env)
		exit (0);
	env->a = ft_pushswapinput(argc, argv);
	env->b = 0;
	env->s = 0;
	env->s = ft_stradd(&(env->s), "");
	i = 0;
	env->b = env->a;
	while (env->b->next)
	{
		env->b = env->b->next;
		i++;
	}
	env->max = i;
	env->mid = env->max / 2;
	env->b = 0;
	return (env);
}
