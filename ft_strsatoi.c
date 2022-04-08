/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsatoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:59:40 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/21 19:56:06 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	**ft_freeints(int **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
		free (arr[i++]);
	if (arr)
		free(arr);
	ft_error();
	return (0);
}

static int	ft_isatoierror(int n, char *s)
{
	size_t	i;
	int		sign;

	sign = 1;
	if (n && n != -1)
		return (0);
	i = 0;
	while (s[i] == ' ' || (s [i] >= 9 && s [i] <= 13))
		i++;
	if (s[i] == '-' || s [i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] == '0')
		i++;
	if ((s[i] == 0) || (s[i] == '1' && sign == -1 && s[i + 1] == 0))
		return (0);
	else
		return (1);
}

static int	**ft_strsatoiloop(int **ints, char **strs, size_t count)
{
	size_t	j;
	int		**res;

	res = ints;
	j = 0;
	while (j < count)
	{
		res[j] = (int *) malloc (sizeof (int));
		if (!res[j])
			return (ft_freeints(res));
		if (strs[j])
			*(res[j]) = ft_atoi (strs[j]);
		else
			res[j] = 0;
		if (ft_isatoierror(*res[j], strs[j]))
			return (ft_freeints(res));
		j++;
	}
	return (res);
}

int	**ft_strsatoi(char **strs)
{
	int		**res;
	size_t	i;
	size_t	j;

	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	res = (int **) malloc ((i + 1) * sizeof (int *));
	if (!res)
		return (0);
	j = 0;
	while (j < i + 1)
		res[j++] = 0;
	return (ft_strsatoiloop(res, strs, i));
}
