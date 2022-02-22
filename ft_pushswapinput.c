/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswapinput.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:24:27 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/18 20:11:18 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_freeintpointers(unsigned int	**ints)
{
	size_t	i;

	if (!ints)
		return ;
	i = 0;
	while (ints[i])
		free (ints[i++]);
	free(ints[i]);
	free (ints);
}

t_stack	*ft_pushswapinput(int argc, char **argv)
{	
	unsigned int	**ints;
	t_stack			*a;
	size_t			i;

	ints = ft_intsnumberedintsfree(ft_intsnstrs(argc, argv));
	a = ft_stacknew(*ints[0]);
	if (!a)
	{
		ft_freeintpointers(ints);
		ft_error();
	}
	i = 1;
	while (ints[i])
	{
		if (!ft_stackadd_back(&a, ft_stacknew(*ints[i])))
		{
			ft_freeintpointers(ints);
			ft_stackclear(&a);
			ft_error();
		}
		i++;
	}
	ft_freeintpointers(ints);
	return (a);
}
