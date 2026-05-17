/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:18:18 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 14:45:36 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void complex_sort(t_stack *a_stack, t_stack *b_stack)
{
    const size_t max_index = a_stack->size;
    size_t bit_mask;
    size_t loop_num;

    bit_mask = 1;
    while(bit_mask <= max_index)
    {
        loop_num = a_stack->size;
        while(loop_num--)
        {
            if (!(a_stack->top->index & bit_mask)) {
                pb()
            } else {
                op_rotate(a_stack);
                ft_printf("ra\n");
            }
        }
        loop_num = b_stack->size;
        while(loop_num--)
        {
            op_push(b_stack, a_stack);
            ft_printf("pa\n");
        }

        bit_mask <<= 1;
    }
}
