/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitstrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:18:37 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/10 15:55:53 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigitstrs(char **strs)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		if (strs[i][0] == '-')
			j++;
		while (strs[i][j])
		{
			if (!ft_isdigit(strs[i][j++]))
				return (0);
		}
		i++;
	}
	return (1);
}
