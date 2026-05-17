/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:39:10 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/17 15:15:57 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

# define ERROR (-1)

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;
typedef struct s_node
{
	int				value;
	size_t				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;
typedef struct s_stack
{
	t_node			*top;
	size_t			size;
}					t_stack;

typedef struct s_ops
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_ops;

typedef enum e_sort_type
{
	NOT_SPECIFIED,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
}					t_sort_type;

typedef struct s_config
{
	t_sort_type		sort_type;
	t_bool			bench;
	float			disorder;
}					t_config;

t_stack *init_stack(void);
t_config *init_config(void);
t_ops *init_ops(void);

/*
** parse_argv: parse argv into a circular doubly linked list and config.
** Returns 0 on success, ERROR on failure. On error the caller is
** expected to print "Error\n" to stderr. Error cases include:
** non-integer arguments, integers outside the int range, duplicates,
** and unknown / duplicated options.
*/
int					parse_argv(int argc, char **argv, t_stack *stack,
						t_config *config);
void				index_stack(t_stack *stack);
void				set_disorder(t_config *config);
/* selection sort */
void				simple_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
/* ... sort */
void				medium_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops);
/* radix sort */
void				complex_sort(t_stack *a_stack, t_stack, t_ops *b_stack);

t_node				*node_new(int value);
t_node				*node_add_prev(t_node *cur, t_node *new);
t_node				*node_add_next(t_node *cur, t_node *new);

void				sa(t_node *a_stack);
void				sb(t_node *b_nodes);
void				ss(t_node *a_stack, t_node *b_stack);
void				pa(t_stack *a_stack, t_stack *b_stack, t_ops *ops); //
void				pb(t_stack *a_stack, t_stack *b_stack, t_ops *ops); //
void				ra(t_stack *a_stack, t_ops *ops_stats); //
void				rb(t_stack *b_stack, t_ops *ops_stats); //
void				rr(t_node *a_stack, t_node *b_stack);
void				rra(t_node *a_stack);
void				rrb(t_node *b_stack);
void				rrr(t_node *a_stack, t_node *b_stack);
void				display_bench(t_ops *ops, t_config *config);

//ran : for test
t_ops	*init_ops_stats(void);
t_stack	*init_stack(void);
void	pa_back(t_stack *a_stack, t_ops *ops, t_node *node);
void	pb_back(t_stack *b_stack, t_ops *ops, t_node *node);
#endif
