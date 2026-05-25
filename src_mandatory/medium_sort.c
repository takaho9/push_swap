/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:18:06 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/25 18:02:35 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunk_pb(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	size_t	i;
	size_t	j;
	size_t	chunk_count;
	size_t	chunk_size;

	chunk_count = ceil_sqrt(a_stack -> size);
	chunk_size = ft_ceil(a_stack -> size, chunk_count);
	i = 0;
	while (i < chunk_count && a_stack -> size > 0)
	{
		j = 0;
		while (j < chunk_size && a_stack -> size > 0)
		{
			if (i * chunk_size <= a_stack -> top -> index
				&& a_stack -> top -> index < (i + 1) * chunk_size)
			{
				pb(a_stack, b_stack, ops);
				j++;
			}
			else
				ra(a_stack, ops);
		}
		i++;
	}
}

static size_t	compute_pos(t_stack *b_stack, size_t cur_max)
{
	size_t	pos;
	t_node	*cur;

	cur = b_stack -> top;
	pos = 0;
	while (pos < b_stack -> size)
	{
		if (cur -> index == cur_max)
			break ;
		pos++;
		cur = cur -> next;
	}
	return (pos);
}

static void	chunk_pa_back(t_stack *a, t_stack *b, t_ops *ops, size_t cur_max)
{
	size_t	pos;

	pos = compute_pos(b, cur_max);
	if (pos > b -> size - pos)
	{
		while (b -> top -> index != cur_max)
			rb(b, ops);
		pa(a, b, ops);
	}
	else
	{
		while (b -> top -> index != cur_max)
			rrb(b, ops);
		pa(a, b, ops);
	}
}

static void	chunk_pa(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	size_t	cur_max;

	cur_max = b_stack -> size - 1;
	while (b_stack -> size > 0)
	{
		if (b_stack -> top -> index == cur_max)
			pa(a_stack, b_stack, ops);
		else
			chunk_pa_back(a_stack, b_stack, ops, cur_max);
		cur_max--;
	}
}

void	medium_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (!a_stack || a_stack -> size < 2)
		return ;
	chunk_pb(a_stack, b_stack, ops);
	chunk_pa(a_stack, b_stack, ops);
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
// 	// input the index
// 	node1 -> index = 0;
// 	node2 -> index = 1;
// 	node3 -> index = 2;
// 	node4 -> index = 3;
// 	node5 -> index = 4;
// 	node6 -> index = 5;
// 	node7 -> index = 6;
// 	node8 -> index = 7;
// 	node9 -> index = 8;
// 	node10 -> index = 9;
// 	node11 -> index = 10;
// 	node12 -> index = 11;
// 	node13 -> index = 12;
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
// 	node11 -> prev = node10;
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
// 	printf("b_stack size : %ld\n", b -> size);
// 	pa(a, b, ops);
// 	pa(a, b, ops);
// 	pa(a, b, ops);
// 	pa(a, b, ops);
// 	pa(a, b, ops);
// 	pa(a, b, ops);
// 	pa(a, b, ops);
// 	pa(a, b, ops);
// 	cur = a -> top;
// 	i = 0;
// 	while (i < a -> size)
// 	{
// 		printf("%d ", cur -> value);
// 		cur = cur -> next;
// 		i++;
// 	}
// 	// test medium sort
// 	medium_sort(a, b, ops);
// 	cur = a -> top;
// 	i = 0;
// 	printf("\ntry to sort a_stack : ");
// 	while (i < a -> size)
// 	{
// 		printf("%d ", cur -> value);
// 		cur = cur -> next;
// 		i++;
// 	}
// }
