/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:18:18 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/27 14:53:03 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	max_bit(size_t max_index)
{
	size_t	bits;

	bits = 0;
	while (max_index > 0)
	{
		bits++;
		max_index >>= 1;
	}
	return (bits);
}

void	complex_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	size_t	bits;
	size_t	bit;
	size_t	loop;

	if (!a_stack || a_stack->size < 2)
		return ;
	if (a_stack -> size <= 5)
	{
		less_than_or_e_5(a_stack, b_stack, ops);
		return ;
	}
	bits = max_bit(a_stack->size - 1);
	bit = 0;
	while (bit < bits)
	{
		loop = a_stack->size;
		while (loop--)
		{
			if (!(a_stack->top->index & (1UL << bit)))
				pb(a_stack, b_stack, ops);
			else
				ra(a_stack, ops);
		}
		loop = b_stack->size;
		while (loop--)
			pa(a_stack, b_stack, ops);
		bit++;
	}
}
