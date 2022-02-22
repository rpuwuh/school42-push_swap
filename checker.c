/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:35:57 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/22 23:13:09 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

static int	ft_isstringaninstruction(char *s)
{
	if (!s)
		return (0);
	if (!ft_strncmp(s, "sa\n", ft_strlen(s))
		|| !ft_strncmp(s, "sb\n", ft_strlen(s))
		|| !ft_strncmp(s, "ss\n", ft_strlen(s))
		|| !ft_strncmp(s, "pa\n", ft_strlen(s))
		|| !ft_strncmp(s, "pb\n", ft_strlen(s))
		|| !ft_strncmp(s, "ra\n", ft_strlen(s))
		|| !ft_strncmp(s, "rb\n", ft_strlen(s))
		|| !ft_strncmp(s, "rr\n", ft_strlen(s))
		|| !ft_strncmp(s, "rra\n", ft_strlen(s))
		|| !ft_strncmp(s, "rrb\n", ft_strlen(s))
		|| !ft_strncmp(s, "rrr\n", ft_strlen(s)))
		return (1);
	return (0);
}

static char	*ft_readactions(void)
{
	char	*s1;
	char	*s2;

	s1 = 0;
	s2 = 0;
	while (1)
	{
		s1 = get_next_line(0);
		if (!s1)
			break ;
		if (!ft_isstringaninstruction(s1))
			ft_error ();
		s2 = ft_stradd(&s2, s1);
		if (s1)
			free (s1);
	}
	return (s2);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	char	*s;

	env = ft_initailize(argc, argv);
	s = ft_readactions();
	if (s && !ft_doactions(env, s))
		ft_error();
	if (env->a && !env->b && ft_isstacksorted(env->a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free (s);
	ft_freenvp(env);
	exit (0);
}
