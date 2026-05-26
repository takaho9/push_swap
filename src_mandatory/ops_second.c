/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_second.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:09:09 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/26 00:00:00 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a_stack, t_ops *ops)
{
	if (!a_stack || a_stack->size < 2)
		return ;
	a_stack->top = a_stack->top->next;
	ops->ra++;
	ops->total++;
	ft_printf("ra\n");
}

void	rb(t_stack *b_stack, t_ops *ops)
{
	if (!b_stack || b_stack->size < 2)
		return ;
	b_stack->top = b_stack->top->next;
	ops->rb++;
	ops->total++;
	ft_printf("rb\n");
}

void	rr(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (!a_stack || !b_stack || a_stack->size < 2 || b_stack->size < 2)
		return ;
	a_stack->top = a_stack->top->next;
	b_stack->top = b_stack->top->next;
	ops->rr++;
	ops->total++;
	ft_printf("rr\n");
}
