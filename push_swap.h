/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:39:10 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/14 21:52:44 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

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

enum				e_sort_type
{
	NOT_SPECIFIED, // 0
	SIMPLE,        // 1
	MEDIUM,        // 2
	COMPLEX,       // 3
	ADAPTIVE,      // 4
};

typedef struct s_config
{
	e_sort_type		sort_type;
	bool			bench;
	float			disorder;
}					t_config;

# define ERROR -1
// if error, return ERROR
//  In case of error,
// it must display "Error" followed by a \n on the standard error.
// Errors include, for example: arguments that are not integers,
// integers outside the
// valid range, or duplicate values.
// index is intialized by 0
int					parse_argv(int argc, char *argv, t_node **nodes,
						t_config *config);
void				index_nodes(t_node **nodes);
void				set_disorder(t_config *config);
void				simple_sort(t_node **node, t_ops *ops);
void				medium_sort(t_node **node, t_ops *ops);
void				complex_sort(t_node **node, t_ops *ops);

void				sa(t_node **a_nodes);
void				sb(t_node **b_nodes);
void				ss(t_node **a_nodes, t_node **b_nodes);
void				pa(t_node **a_nodes, t_node **b_nodes); // priority high
void				pb(t_node **a_nodes, t_node **b_nodes); // priority high
void				ra(t_node **a_nodes); // priority high
void				rb(t_node **b_nodes);
void				rr(t_node **a_nodes, t_node **b_nodes);
void				rra(t_node **a_nodes);
void				rrb(t_node **b_nodes);
void				rrr(t_node **a_nodes, t_node **b_nodes);
void				display_bench(t_ops ops, t_config config);
#endif
