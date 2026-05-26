/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:22:36 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/25 23:30:00 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	size_t	i;

	if (!a_stack || a_stack->size < 2)
		return ;
	i = 0;
	while (a_stack->top)
	{
		if (a_stack->top->index == i)
		{
			pb(a_stack, b_stack, ops);
			i++;
		}
		else
			ra(a_stack, ops);
	}
	while (b_stack->top)
		pa(a_stack, b_stack, ops);
}
