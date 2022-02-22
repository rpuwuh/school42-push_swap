/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:12:57 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/22 18:43:45 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	env = ft_initailize(argc, argv);
	ft_choosesort(env);
	ft_putstr_fd(env->s, 1);
	ft_freenvp(env);
	exit (0);
}	
