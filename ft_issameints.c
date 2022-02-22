/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issameints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:17:15 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/11 19:21:34 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issameints(int **ints)
{
	size_t	i;
	size_t	j;

	if (!ints || !*ints)
		return (0);
	i = 0;
	j = 1;
	while (ints[i] && ints[j])
	{
		j = i + 1;
		while (ints[j])
			if (*(ints[i]) == *(ints[j++]))
				return (1);
		j = i + 1;
		i++;
	}
	return (0);
}
