/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_second.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:09:09 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/17 15:36:24 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a_stack, t_ops *ops_stats)
{
	if (a_stack -> size < 2)
		return ;
	a_stack -> top = a_stack -> top -> next;
	ops_stats -> ra++;
	ops_stats -> total++;
	// ft_printf("ra\n");
}// priority high


void	rb(t_stack *b_stack, t_ops *ops_stats)
{
	if (b_stack -> size < 2)
		return ;
	b_stack -> top = b_stack -> top -> next;
	ops_stats -> rb++;
	ops_stats -> total++;
	// ft_printf("ra\n");
}// priority high

void	rr(t_stack *a_stack, t_stack *b_stack, t_ops *ops_stats)
{
	if (a_stack -> size < 2 || b_stack -> size < 2)
		return ;
	a_stack -> top = a_stack -> top -> next;
	b_stack -> top = b_stack -> top -> next;
	ops_stats -> rr++;
	ops_stats -> total++;
	ft_printf("rr\n");
}

void	rra(t_stack *a_stack, t_ops *ops_stats)
{
	if (a_stack -> size < 2)
		return ;
	a_stack -> top = a_stack -> top -> prev;
	ops_stats -> rra++;
	ops_stats -> total;
	ft_printf("rra\n");
}

void	rrb(t_stack *b_stack, t_ops *ops_stats)
{
	if (b_stack -> size < 2)
		return ;
	b_stack -> top = b_stack -> top -> prev;
	ops_stats -> rrb++;
	ops_stats -> total;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a_stack, t_stack *b_stack, t_ops *ops_stats)
{
	if (a_stack -> size < 2 || b_stack -> size < 2)
		return ;
	a_stack -> top = a_stack -> top -> prev;
	b_stack -> top = b_stack -> top -> prev;
	ops_stats -> rrr++;
	ops_stats -> total++;
	ft_printf("rrr\n");
}


// #include <stdio.h>
// int	main(void)
// {
// 	t_node	*a_nodes;
// 	t_node	*b_nodes;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;
// 	t_node	*cur;
// 	t_stack	*a_stack;
// 	t_stack	*b_stack;
// 	t_ops	*ops;

// 	a_stack = init_stack();
// 	b_stack = init_stack();
// 	ops = init_ops_stats();
// 	a_nodes = node_new(5);
// 	b_nodes = node_new(6);
// 	node1 = node_new(1);
// 	node2 = node_new(2);
// 	node3 = node_new(3);
// 	b_nodes -> next = node1;
// 	node1 -> prev = b_nodes;
// 	node1 -> next = node2;
// 	node2 -> prev = node1;
// 	node2 -> next = node3;
// 	node3 -> prev = node2;
// 	node3 -> next = b_nodes;
// 	b_nodes -> prev = node3;
// 	a_stack -> top = a_nodes;
// 	a_stack -> size = 1;
// 	b_stack -> top = b_nodes;
// 	b_stack -> size = 4;
// 	cur = b_stack -> top;
// 	a_nodes -> prev = a_nodes;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		printf("%d\n", cur -> value);
// 		cur = cur -> next;
// 	}
// 	printf("b_stack size : %ld\n", b_stack -> size);
// 	pa(a_stack, b_stack, ops);
// 	cur = b_stack -> top;
// 	printf("\n");
// 	for (int i = 0; i < 3; i++)
// 	{
// 		printf("%d\n", cur -> value);
// 		cur = cur -> next;
// 	}
// 	printf("\n");
// 	printf("b_stack size : %ld\n", b_stack -> size);
// 	cur = a_stack -> top;
// 	for (int i = 0; i < 2; i++)
// 	{
// 		printf("%d\n", cur -> value);
// 		cur = cur -> next;
// 	}
// 	printf("\n");
// 	printf("a_stack size : %ld\n", a_stack -> size);
// 	ra(a_stack, ops);
// 	cur = a_stack -> top;
// 	for (int i = 0; i < 2; i++)
// 	{
// 		printf("%d\n", cur -> value);
// 		cur = cur -> next;
// 	}
// 	printf("\n");
// 	rb(b_stack, ops);
// 	cur = b_stack -> top;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		printf("%d\n", cur -> value);
// 		cur = cur -> next;
// 	}
// }