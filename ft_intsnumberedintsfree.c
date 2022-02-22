/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsnumberedintsfree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:16:51 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/18 20:08:06 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_freeintpointers(int	**ints)
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

static unsigned int	**ft_mallocints(int **ints)
{
	unsigned int		**ints_ordered;
	size_t				i;

	i = 0;
	while (ints[i])
		i++;
	ints_ordered = (unsigned int **) malloc ((i + 1) * sizeof (unsigned int *));
	if (!ints_ordered)
	{
		ft_freeintpointers(ints);
		exit (0);
	}
	i = 0;
	while (ints[i])
	{
		ints_ordered[i] = (unsigned int *) malloc (sizeof (unsigned int));
		if (!ints_ordered)
		{
			ft_freeintpointers((int **) ints_ordered);
			ft_freeintpointers(ints);
			ft_error();
		}
		i++;
	}
	return (ints_ordered);
}

unsigned int	**ft_intsnumberedintsfree(int **ints)
{
	unsigned int		**ints_ordered;
	size_t				i;
	size_t				j;

	ints_ordered = ft_mallocints(ints);
	i = 0;
	while (ints[i])
	{
		j = 0;
		(*(ints_ordered[i])) = 0;
		while (ints[j])
		{
			if (i != j && *ints[i] > *ints[j])
				(*(ints_ordered[i]))++;
			j++;
		}
		i++;
	}
	(ints_ordered[i]) = 0;
	ft_freeintpointers(ints);
	return (ints_ordered);
}
