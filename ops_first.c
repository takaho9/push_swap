/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:08:21 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/19 11:01:00 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	t_node	*bottom;
	t_node	*node;

	if (!a_stack || !b_stack || b_stack -> size == 0)
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
	pa_back(a_stack, ops, node);
}

void	pa_back(t_stack *a_stack, t_ops *ops, t_node *node)
{
	t_node	*bottom;

	if (!a_stack || a_stack -> size == 0)
	{
		node -> prev = node;
		node -> next = node;
		a_stack -> top = node;
	}
	else
		a_stack -> top = node_add_prev(a_stack -> top, node);
	a_stack -> size++;
	ops -> pa++;
	ops -> total++;
	// ft_printf("pa\n");
}

void	pb(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	t_node	*bottom;
	t_node	*node;

	if (!a_stack || !b_stack || a_stack -> size == 0)
		return ;
	node = a_stack -> top;
	if (a_stack -> size == 1)
		a_stack -> top = NULL;
	else
	{
		bottom = a_stack -> top -> prev;
		a_stack -> top = node -> next;
		bottom -> next = a_stack -> top;
		a_stack -> top -> prev = bottom;
	}
	a_stack -> size--;
	pb_back(b_stack, ops, node);
}

void	pb_back(t_stack *b_stack, t_ops *ops, t_node *node)
{
	t_node	*bottom;

	if (!b_stack || b_stack -> size == 0)
	{
		node -> prev = node;
		node -> next = node;
		b_stack -> top = node;
	}
	else
		b_stack -> top = node_add_prev(b_stack -> top, node);
	b_stack -> size++;
	ops -> pb++;
	ops -> total++;
	// ft_printf("pa\n");
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
// 	ops = init_ops();
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