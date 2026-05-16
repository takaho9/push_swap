/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:22:36 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/16 21:39:23 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void simple_sort(t_stack *stack_a, t_stack *stack_b)
{
    size_t i;

    i = 0;
    while(stack_a->top)
    {
        if(stack_a->top->index == i) {
            op_push(stack_a, stack_b);
            ft_printf("pb\n");
            i++;
        } else {
            op_rotate(stack_a);
            ft_printf("ra\n");
        }
    }

    while(stack_b->top)
    {
        op_push(stack_b, stack_a);
        ft_printf("pa\n");
    }
}
