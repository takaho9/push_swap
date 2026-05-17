/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:22:36 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 14:46:46 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void simple_sort(t_stack *a_stack, t_stack *b_stack)
{
    size_t i;

    i = 0;
    while(a_stack->top)
    {
        if(a_stack->top->index == i) {
            op_push(a_stack, b_stack);
            ft_printf("pb\n");
            i++;
        } else {
            op_rotate(a_stack);
            ft_printf("ra\n");
        }
    }

    while(b_stack->top)
    {
        op_push(b_stack, a_stack);
        ft_printf("pa\n");
    }
}
