/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:00:00 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/26 00:00:00 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a_stack, t_ops *ops)
{
	if (!a_stack || a_stack->size < 2)
		return ;
	a_stack->top = a_stack->top->prev;
	ops->rra++;
	ops->total++;
	ft_printf("rra\n");
}

void	rrb(t_stack *b_stack, t_ops *ops)
{
	if (!b_stack || b_stack->size < 2)
		return ;
	b_stack->top = b_stack->top->prev;
	ops->rrb++;
	ops->total++;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (!a_stack || !b_stack || a_stack->size < 2 || b_stack->size < 2)
		return ;
	a_stack->top = a_stack->top->prev;
	b_stack->top = b_stack->top->prev;
	ops->rrr++;
	ops->total++;
	ft_printf("rrr\n");
}
