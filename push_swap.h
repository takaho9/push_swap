/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:39:10 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/16 17:30:51 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

# define ERROR (-1)

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;
typedef	struct s_stack
{
	t_node	*top;
	int	size;
}	t_stack;


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

/*
** parse_argv: parse argv into a circular doubly linked list and config.
** Returns 0 on success, ERROR on failure. On error the caller is
** expected to print "Error\n" to stderr. Error cases include:
** non-integer arguments, integers outside the int range, duplicates,
** and unknown / duplicated options.
*/
int					parse_argv(int argc, char **argv, t_node **nodes,
						t_config *config);
void				index_nodes(t_node **nodes);
void				set_disorder(t_config *config);
void				simple_sort(t_node **node, t_ops *ops);
void				medium_sort(t_node **node, t_ops *ops);
void				complex_sort(t_node **node, t_ops *ops);

t_node				*node_new(int value);
t_node				*node_add_prev(t_node *cur, t_node *new);
t_node				*node_add_next(t_node *cur, t_node *new);

void				sa(t_node **a_nodes);
void				sb(t_node **b_nodes);
void				ss(t_node **a_nodes, t_node **b_nodes);
void				pa(t_node **a_nodes, t_node **b_nodes);
void				pb(t_node **a_nodes, t_node **b_nodes);
void				ra(t_node **a_nodes);
void				rb(t_node **b_nodes);
void				rr(t_node **a_nodes, t_node **b_nodes);
void				rra(t_node **a_nodes);
void				rrb(t_node **b_nodes);
void				rrr(t_node **a_nodes, t_node **b_nodes);
void				display_bench(t_ops ops, t_config config);

//ran : for test
t_node	*create_elem(int value);

#endif
