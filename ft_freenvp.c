/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freenvp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:05:36 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/18 20:12:26 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freenvp(t_env *env)
{
	free(env->s);
	ft_stackclear(&(env->a));
	ft_stackclear(&(env->b));
	free (env);
}
