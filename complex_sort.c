/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:18:18 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/16 20:52:19 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void complex_sort(t_stack *stack_a, t_stack *stack_b)
{
    const size_t max_index = stack_a->size;
    size_t bit_mask;
    size_t loop_num;

    bit_mask = 1;
    while(bit_mask <= max_index)
    {
        loop_num = stack_a->size;
        while(loop_num--)
        {
            if (!(stack_a->top->index & bit_mask)) {
                op_push(stack_a, stack_b);
                ft_printf("pb\n");
            } else {
                op_rotate(stack_a);
                ft_printf("ra\n");
            }
        }
        loop_num = stack_b->size;
        while(loop_num--)
        {
            op_push(stack_b, stack_a);
            ft_printf("pa\n");
        }

        bit_mask <<= 1;
    }
}
