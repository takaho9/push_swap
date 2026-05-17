/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:51 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/17 18:47:42 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	set_disorder(t_stack *a_stack)
{
	t_node	*node_i;
	t_node	*node_j;
	size_t	mistake;
	size_t	total_pairs;

	mistake = 0;
	if (!a_stack || a_stack -> size < 2)
		return (0.0);
	total_pairs = (a_stack -> size) * (a_stack -> size - 1) / 2;
	node_i = a_stack -> top;
	node_j = node_i -> next;
	return (compute_disorder(a_stack, node_i, node_j, mistake, total_pairs));
}

double	compute_disorder(t_stack *a_stack, t_node *node_i, t_node *node_j, size_t mistake, size_t total_pairs)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (a_stack -> size - 1))
	{
		j = i + 1;
		node_j = node_i -> next;
		while (j < a_stack -> size)
		{
			if (node_i -> index > node_j -> index)
				mistake++;
			node_j = node_j -> next;
			j++;
		}
		node_i = node_i -> next;
		i++;
	}
	return ((double)mistake / (double)total_pairs);
}

// test : change the function camparing value insdead of index
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
// 	t_ops *ops =init_ops();
// 	t_stack *b = init_stack();

// 	//create stack a
// 	a -> top = node1;
// 	a -> size = 13;
// 	node1 -> next = node2;
// 	node2 -> next = node3;
// 	node3 -> next = node4;
// 	node4 -> next = node5;
// 	node5 -> next = node6;
// 	node6 -> next = node7;
// 	node7 -> next = node8;
// 	node8 -> next = node9;
// 	node9 -> next = node10;
// 	node10 -> next = node11;
// 	node11 -> next = node12;
// 	node12 -> next = node13;
// 	node13 -> next = node1;
// 	node1 -> prev = node13;
// 	node13-> prev = node12;
// 	node12 -> prev = node11;
// 	node11 -> prev = node10;
// 	node10 -> prev = node9;
// 	node9 -> prev = node8;
// 	node8 -> prev = node7;
// 	node7 -> prev = node6;
// 	node6 -> prev = node5;
// 	node5 -> prev = node4;
// 	node4 -> prev = node3;
// 	node3 -> prev = node2;
// 	node2 -> prev = node1;
// 	printf("%f\n", set_disorder(a));
// 	ra(a, ops);
// 	pb(a, b, ops);
// 	printf("%f\n", set_disorder(a));
// }
