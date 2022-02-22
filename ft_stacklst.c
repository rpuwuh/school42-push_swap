/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:51 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/20 14:46:31 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(unsigned int num)
{
	t_stack	*res;

	res = (t_stack *) malloc (sizeof(t_stack));
	if (!res)
		return (0);
	res->num = num;
	res->next = 0;
	res->score = 0;
	return (res);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	if (!new)
		return (0);
	if (!lst || !(*lst))
		*lst = new;
	else
		ft_stacklast(*lst)->next = new;
	return (1);
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*pointer;
	t_stack	*prev;

	if (!lst || !(*lst))
		return ;
	pointer = *lst;
	while (pointer->next)
	{
		prev = pointer;
		pointer = pointer->next;
		prev->num = 0;
		free(prev);
	}
	pointer->num = 0;
	free(pointer);
	*lst = 0;
}

unsigned int	ft_stackcount(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
