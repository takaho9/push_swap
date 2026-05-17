/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_second.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:09:09 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/17 18:17:14 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a_stack, t_ops *ops)
{
	if (!a_stack || a_stack -> size < 2)
		return ;
	a_stack -> top = a_stack -> top -> next;
	ops -> ra++;
	ops -> total++;
	// ft_printf("ra\n");
}


void	rb(t_stack *b_stack, t_ops *ops)
{
	if (!b_stack || b_stack -> size < 2)
		return ;
	b_stack -> top = b_stack -> top -> next;
	ops -> rb++;
	ops -> total++;
	// ft_printf("ra\n");
}

void	rr(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (!a_stack || !b_stack || a_stack -> size < 2 || b_stack -> size < 2)
		return ;
	a_stack -> top = a_stack -> top -> next;
	b_stack -> top = b_stack -> top -> next;
	ops -> rr++;
	ops -> total++;
	// ft_printf("rr\n");
}

void	rra(t_stack *a_stack, t_ops *ops)
{
	if (!a_stack || a_stack -> size < 2)
		return ;
	a_stack -> top = a_stack -> top -> prev;
	ops -> rra++;
	ops -> total++;
	// ft_printf("rra\n");
}

void	rrb(t_stack *b_stack, t_ops *ops)
{
	if (!b_stack || b_stack -> size < 2)
		return ;
	b_stack -> top = b_stack -> top -> prev;
	ops -> rrb++;
	ops -> total++;
	// ft_printf("rrb\n");
}

void	rrr(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (!a_stack || !b_stack || a_stack -> size < 2 || b_stack -> size < 2)
		return ;
	a_stack -> top = a_stack -> top -> prev;
	b_stack -> top = b_stack -> top -> prev;
	ops -> rrr++;
	ops -> total++;
	// ft_printf("rrr\n");
}

// #include <stdio.h>
// int	main(void)
// {
// 	//create nodes
// 	t_node	*node1 = node_new(1);
// 	t_node	*node2 = node_new(2);
// 	t_node	*node3 = node_new(3);
// 	t_node	*node4 = node_new(4);
// 	t_node	*node5 = node_new(5);
// 	t_node	*node6 = node_new(6);
// 	t_node	*node7 = node_new(7);
// 	t_node	*node8 = node_new(8);
// 	t_node	*node9 = node_new(9);
// 	t_node	*node10 = node_new(10);
// 	t_node	*node11 = node_new(11);
// 	t_node	*node12 = node_new(12);
// 	t_node	*node13 = node_new(13);
// 	t_stack	*a = init_stack();
// 	t_stack	*b = init_stack();
// 	t_ops	*ops = init_ops();
// 	t_node	*cur;
// 	size_t	i;

// 	i = 0;
// 	//create stack a
// 	a -> top = node1;
// 	a -> size = 5;
// 	node1 -> next = node2;
// 	node2 -> next = node3;
// 	node3 -> next = node4;
// 	node4 -> next = node5;
// 	node5 -> next = node1;
// 	node1 -> prev = node5;
// 	node5 -> prev = node4;
// 	node4 -> prev = node3;
// 	node3 -> prev = node2;
// 	node2 -> prev = node1;
// 	//create stack b
// 	b -> top = node6;
// 	b -> size = 8;
// 	node6 -> next = node7;
// 	node7 -> next = node8;
// 	node8 -> next = node9;
// 	node9 -> next = node10;
// 	node10 -> next = node11;
// 	node11 -> next = node12;
// 	node12 -> next = node13;
// 	node13 -> next = node6;
// 	node6 -> prev = node13;
// 	node13 -> prev = node12;
// 	node12 -> prev = node11;
// 	node10 -> prev = node9;
// 	node9 -> prev = node8;
// 	node8 -> prev = node7;
// 	node7 -> prev = node6;
// 	//test ra
// 	cur = a -> top;
// 	printf("a_stack origin: ");
// 	while (i < a -> size)
// 	{
// 		printf("%d ", cur -> value);
// 		cur = cur -> next;
// 		i++;
// 	}
// 	printf("\nra : %d\n", ops -> ra);
// 	ra(a, ops);
// 	cur = a -> top;
// 	i = 0;
// 	while (i < a -> size)
// 	{
// 		printf("%d ", cur -> value);
// 		cur = cur -> next;
// 		i++;
// 	}
// 	printf("\nra : %d\n", ops -> ra);
// 	//test rb
// 	cur = b -> top;
// 	i = 0;
// 	printf("b_stack origin: ");
// 	while (i < b -> size)
// 	{
// 		printf("%d ", cur -> value);
// 		cur = cur -> next;
// 		i++;
// 	}
// 	printf("\nrb : %d\n", ops -> rb);
// 	rb(b, ops);
// 	cur = b -> top;
// 	i = 0;
// 	while (i < b -> size)
// 	{
// 		printf("%d ", cur -> value);
// 		cur = cur -> next;
// 		i++;
// 	}
// 	printf("\nrb : %d\n", ops -> rb);
// }
