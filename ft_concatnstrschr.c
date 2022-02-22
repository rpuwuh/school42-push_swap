/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concatnstrschr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:33:08 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/22 21:06:14 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_cleanfreestring(char **s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s && *s[i])
		*s[i] = '\0';
	if (*s)
		free(*s);
	*s = 0;
	return (0);
}

static char	*ft_freestrs(char *s1, char *s2)
{
	ft_cleanfreestring(&s1);
	ft_cleanfreestring(&s2);
	return (0);
}

char	*ft_concatnstrschr(int argc, char **argv, char *c)
{
	char	*res;
	char	*temp;
	int		i;

	if (argc <= 1 || !argv || !(*argv))
		exit (0);
	res = ft_strdup(argv[1]);
	if (!res)
		return (0);
	i = 2;
	while (i < argc)
	{
		temp = ft_strjoin(res, c);
		if (!temp)
			return (ft_freestrs(res, temp));
		ft_cleanfreestring(&res);
		res = temp;
		temp = ft_strjoin(res, argv[i]);
		if (!temp)
			return (ft_freestrs(res, temp));
		ft_cleanfreestring(&res);
		res = temp;
		i++;
	}
	return (res);
}
