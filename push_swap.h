/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:14:56 by bpoetess          #+#    #+#             */
/*   Updated: 2022/02/22 19:02:54 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	unsigned int	num;
	unsigned int	score;
	struct s_stack	*next;
}	t_stack;

typedef struct s_env
{
	t_stack			*a;
	t_stack			*b;
	char			*s;
	unsigned int	max;
	unsigned int	mid;
}	t_env;

char				*ft_concatnstrschr(int argc, char **argv, char *c);

void				ft_error(void);

int					ft_isdigitstrs(char **strs);

int					**ft_strsatoi(char **strs);

int					ft_issameints(int **ints);

int					**ft_intsnstrs(int argc, char **argv);

unsigned int		**ft_intsnumberedintsfree(int **ints);

t_stack				*ft_stacknew(unsigned int num);
t_stack				*ft_stacklast(t_stack *lst);
int					ft_stackadd_back(t_stack **lst, t_stack *new);
void				ft_stackclear(t_stack **lst);
unsigned int		ft_stackcount(t_stack *stack);

t_stack				*ft_pushswapinput(int argc, char **argv);

int					ft_isstacksorted(t_stack *a);
int					ft_isstackrevsorted(t_stack *b);

char				*ft_stradd(char	**dest, char *src);

t_env				*ft_initailize(int argc, char **argv);

void				ft_freenvp(t_env *env_p);

void				ft_sa(t_env *env);
void				ft_sb(t_env *env);
void				ft_ss(t_env *env);

void				ft_pa(t_env *env);
void				ft_pb(t_env *env);

void				ft_ra(t_env *env);
void				ft_rb(t_env *env);
void				ft_rr(t_env *env);

void				ft_rra(t_env *env);
void				ft_rrb(t_env *env);
void				ft_rrr(t_env *env);

void				ft_sortathree(t_env *env);
void				ft_sortbthree(t_env *env);

int					ft_isnotstrictlysorted(t_stack *a);
int					ft_isnotstrictlyrevsorted(t_stack *a, t_env *env);

void				ft_choosesort(t_env *env);
unsigned int		ft_findrastacknum(t_stack *a, unsigned int n);

void				ft_middlesort(t_env *env);

unsigned int		ft_score_rb(t_env *env, unsigned int n);
unsigned int		ft_score_ra(t_env *env, unsigned int n);
unsigned int		ft_score_rrb(t_env *env, unsigned int n);
unsigned int		ft_score_rra(t_env *env, unsigned int n);

unsigned int		ft_minuint(unsigned int n1, unsigned int n2);
unsigned int		ft_maxuint(unsigned int n1, unsigned int n2);
unsigned int		ft_score(t_env *env, unsigned int n);

void				ft_doscore(t_env *env);
unsigned int		ft_choosescore(t_env *env);
unsigned int		ft_findnumscore(t_env *env, unsigned int score);
void				ft_chooseaction(t_env *env, unsigned int n, unsigned int s);

void				ft_rrandra(t_env *env, unsigned int n1, unsigned int n2);
void				ft_rrandrb(t_env *env, unsigned int n1, unsigned int n2);
void				ft_rrrandrra(t_env *env, unsigned int n1, unsigned int n2);
void				ft_rrrandrrb(t_env *env, unsigned int n1, unsigned int n2);
void				ft_raandrrb(t_env *env, unsigned int n1, unsigned int n2);

void				ft_rollstacknum(t_env *env, t_stack **st, unsigned int n);
void				ft_firstpush(t_env *env);
void				ft_middlesort(t_env *env);

#endif
