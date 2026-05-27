/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:18:06 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/27 14:52:53 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunk_pb(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	size_t	i;
	size_t	j;
	size_t	chunk_count;
	size_t	chunk_size;

	chunk_count = ceil_sqrt(a_stack->size);
	chunk_size = ft_ceil(a_stack->size, chunk_count);
	i = 0;
	while (i < chunk_count && a_stack->size > 0)
	{
		j = 0;
		while (j < chunk_size && a_stack->size > 0)
		{
			if (i * chunk_size <= a_stack->top->index
				&& a_stack->top->index < (i + 1) * chunk_size)
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

	cur = b_stack->top;
	pos = 0;
	while (pos < b_stack->size)
	{
		if (cur->index == cur_max)
			break ;
		pos++;
		cur = cur->next;
	}
	return (pos);
}

static void	chunk_pa_back(t_stack *b_stack, t_ops *ops, size_t cur_max)
{
	size_t	pos;

	pos = compute_pos(b_stack, cur_max);
	if (pos <= b_stack->size - pos)
	{
		while (b_stack->top->index != cur_max)
			rb(b_stack, ops);
	}
	else
	{
		while (b_stack->top->index != cur_max)
			rrb(b_stack, ops);
	}
}

static void	chunk_pa(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	size_t	cur_max;

	if (b_stack->size == 0)
		return ;
	cur_max = b_stack->size - 1;
	while (b_stack->size > 0)
	{
		if (b_stack->top->index != cur_max)
			chunk_pa_back(b_stack, ops, cur_max);
		pa(a_stack, b_stack, ops);
		if (cur_max == 0)
			break ;
		cur_max--;
	}
}

void	medium_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (!a_stack || a_stack->size < 2)
		return ;
	if (a_stack -> size <= 5)
	{
		less_than_or_e_5(a_stack, b_stack, ops);
		return ;
	}
	chunk_pb(a_stack, b_stack, ops);
	chunk_pa(a_stack, b_stack, ops);
}
