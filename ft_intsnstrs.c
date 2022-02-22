/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsnstrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:44:29 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/18 19:58:36 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_freeintpointerserror(int	**ints)
{
	size_t	i;

	if (!ints)
		return ;
	i = 0;
	while (ints[i])
		free (ints[i++]);
	free(ints[i]);
	free (ints);
	ft_error();
}

static void	ft_freecharpointers(char **strs)
{
	size_t	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free (strs[i++]);
	free(strs[i]);
	free(strs);
}

int	**ft_intsnstrs(int argc, char **argv)
{
	char	*s;
	char	**args_splited;
	int		**ints;

	s = ft_concatnstrschr(argc, argv, " ");
	if (!s)
		ft_error();
	args_splited = ft_split(s, ' ');
	free (s);
	if (!args_splited)
		ft_error();
	if (!ft_isdigitstrs(args_splited))
	{
		ft_freecharpointers(args_splited);
		ft_error();
	}
	ints = ft_strsatoi(args_splited);
	ft_freecharpointers(args_splited);
	if (!ints || ft_issameints(ints))
		ft_freeintpointerserror(ints);
	return (ints);
}
