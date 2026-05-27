/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:22:36 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/27 14:49:42 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// insertion sort
static void	rotate_b_to(t_stack *b_stack, t_ops *ops, size_t pos)
{
	size_t	size;

	size = b_stack->size;
	if (size < 2 || pos == 0)
		return ;
	if (pos <= size / 2)
	{
		while (pos--)
			rb(b_stack, ops);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(b_stack, ops);
	}
}

static size_t	find_insert_pos(size_t a_idx, t_stack *b_stack)
{
	t_node	*cur;
	size_t	max_idx;
	size_t	max_pos;
	size_t	i;

	if (b_stack->size < 2)
		return (0);
	cur = b_stack->top;
	max_idx = cur->index;
	max_pos = 0;
	i = 0;
	while (i < b_stack->size)
	{
		if (cur->index < a_idx && cur->prev->index > a_idx)
			return (i);
		if (cur->index > max_idx)
		{
			max_idx = cur->index;
			max_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (max_pos);
}

void	simple_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (!a_stack || a_stack->size < 2)
		return ;
	if (a_stack -> size <= 5)
	{
		less_than_or_e_5(a_stack, b_stack, ops);
		return ;
	}
	while (a_stack->size)
	{
		rotate_b_to(b_stack, ops, find_insert_pos(a_stack->top->index,
				b_stack));
		pb(a_stack, b_stack, ops);
	}
	rotate_b_to(b_stack, ops, (b_stack->top->index + 1) % b_stack->size);
	while (b_stack->size)
		pa(a_stack, b_stack, ops);
}
// selection sort
// void	simple_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
// {
// 	size_t	i;

// 	if (!a_stack || a_stack->size < 2)
// 		return ;
// 	i = 0;
// 	while (a_stack->top)
// 	{
// 		if (a_stack->top->index == i)
// 		{
// 			pb(a_stack, b_stack, ops);
// 			i++;
// 		}
// 		else
// 			ra(a_stack, ops);
// 	}
// 	while (b_stack->top)
// 		pa(a_stack, b_stack, ops);
// }
