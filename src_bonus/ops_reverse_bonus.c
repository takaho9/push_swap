/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:00:00 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/26 00:00:00 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_bonus(t_stack *a_stack)
{
	if (!a_stack || a_stack->size < 2)
		return ;
	a_stack->top = a_stack->top->prev;
}

void	rrb_bonus(t_stack *b_stack)
{
	if (!b_stack || b_stack->size < 2)
		return ;
	b_stack->top = b_stack->top->prev;
}

void	rrr_bonus(t_stack *a_stack, t_stack *b_stack)
{
	if (!a_stack || !b_stack || a_stack->size < 2 || b_stack->size < 2)
		return ;
	a_stack->top = a_stack->top->prev;
	b_stack->top = b_stack->top->prev;
}
