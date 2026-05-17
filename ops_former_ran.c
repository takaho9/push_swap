/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_former_ran.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:08:21 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/17 14:17:13 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	pa(t_stack *a_stack, t_stack *b_stack, t_ops *ops) // priority high
{
	t_node	*bottom;
	t_node	*node;

	if (b_stack -> size == 0)
		return ;
	node = b_stack -> top;
	if (b_stack -> size == 1)
		b_stack -> top = NULL;
	else
	{
		bottom = b_stack -> top -> prev;
		b_stack -> top = node -> next;
		bottom -> next = b_stack -> top;
		b_stack -> top -> prev = bottom;
	}
	b_stack -> size--;
	if (a_stack -> size == 0)
	{
		node -> prev = node;
		node -> next = node;
		a_stack -> top = node;
	}
	else
	{
		bottom = a_stack -> top -> prev;
		bottom -> next = node;
		a_stack -> top -> next -> prev = node;
		node -> prev =bottom;
		node -> next =  a_stack -> top -> next -> prev;
		a_stack -> top = node;
	}
	a_stack -> size++;
	ops -> pa++;
	ops -> total++;
	// ft_printf("pa\n");
}

// void				pb(t_node **a_nodes, t_node **b_nodes); // priority high

// void				ra(t_node **a_nodes); // priority high


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
// 	ops = init_ops();
// 	a_nodes = node_new(5);
// 	b_nodes = node_new(5);
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
// 	cur = b_nodes;
// 	a_nodes -> prev = a_nodes;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		printf("%d\n", cur -> value);
// 		cur = cur -> next;
// 	}
// 	printf("b_stack size : %d\n", b_stack -> size);
// 	pa(a_stack, b_stack, ops);
// 	cur = b_nodes;
// 	printf("\n");
// 	for (int i = 0; i < 3; i++)
// 	{
// 		printf("%d\n", cur -> value);
// 		cur = cur -> next;
// 	}
// 	printf("\n");
// 	printf("b_stack size : %d\n", b_stack -> size);
// 	cur = a_nodes;
// 	for (int i = 0; i < 2; i++)
// 	{
// 		printf("%d\n", cur -> value);
// 		cur = cur -> next;
// 	}
// 	printf("\n");
// 	printf("a_stack size : %d\n", a_stack -> size);
// }