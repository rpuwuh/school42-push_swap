/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:41:06 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/22 20:00:37 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_stradd(char	**dest, char *src)
{
	char	*res;

	if (!dest)
		return (0);
	if (!src)
		return (*dest);
	if (!(*dest))
		return (ft_strdup(src));
	res = ft_strjoin(*dest, src);
	free(*dest);
	*dest = res;
	return (res);
}
