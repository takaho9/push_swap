/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:39:10 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/27 14:48:42 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_node
{
	int				value;
	size_t			index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}	t_stack;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_ops;

typedef enum e_sort_type
{
	NOT_SPECIFIED,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_sort_type;

typedef struct s_config
{
	t_sort_type	sort_type;
	t_sort_type	executed;
	t_bool		bench;
	double		disorder;
}	t_config;

/* init / cleanup */
t_stack		*init_stack(void);
t_config	*init_config(void);
t_ops		*init_ops(void);
void		free_stack(t_stack *stack);
void		cleanup_all(t_stack *a_stack, t_stack *b_stack, t_config *config,
				t_ops *ops);
void		error_exit(t_stack *a_stack, t_stack *b_stack, t_config *config,
				t_ops *ops);

/* parsing / setup */
int			parse_argv(int argc, char **argv, t_stack *stack, t_config *config);
int			set_stack(t_stack *stack, char *str);
void		index_stack(t_stack *stack);
int			is_sorted(t_stack *a_stack);
double		set_disorder(t_stack *a_stack);

/* sorts */
void		less_than_or_e_5(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
void		simple_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
void		medium_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
void		complex_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops);

/* node helpers */
t_node		*node_new(int value);
t_node		*node_add_prev(t_node *cur, t_node *new);

/* push_swap operations */
void		sa(t_stack *a_stack, t_ops *ops);
void		sb(t_stack *b_stack, t_ops *ops);
void		ss(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
void		pa(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
void		pa_back(t_stack *a_stack, t_ops *ops, t_node *node);
void		pb(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
void		pb_back(t_stack *b_stack, t_ops *ops, t_node *node);
void		ra(t_stack *a_stack, t_ops *ops);
void		rb(t_stack *b_stack, t_ops *ops);
void		rr(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
void		rra(t_stack *a_stack, t_ops *ops);
void		rrb(t_stack *b_stack, t_ops *ops);
void		rrr(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
void		display_bench(t_ops *ops, t_config *config);

/* math (medium sort) */
size_t		ceil_sqrt(size_t n);
size_t		ft_ceil(size_t dividend, size_t divisor);

/* bonus / checker */
void		sa_bonus(t_stack *a_stack);
void		sb_bonus(t_stack *b_stack);
void		ss_bonus(t_stack *a_stack, t_stack *b_stack);
void		pa_bonus(t_stack *a_stack, t_stack *b_stack);
void		pb_bonus(t_stack *a_stack, t_stack *b_stack);
void		ra_bonus(t_stack *a_stack);
void		rb_bonus(t_stack *b_stack);
void		rr_bonus(t_stack *a_stack, t_stack *b_stack);
void		rra_bonus(t_stack *a_stack);
void		rrb_bonus(t_stack *b_stack);
void		rrr_bonus(t_stack *a_stack, t_stack *b_stack);

#endif
