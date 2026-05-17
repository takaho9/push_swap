/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:18:18 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 15:02:20 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void complex_sort(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
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
            if (!(a_stack->top->index & bit_mask))
                pb(a_stack, b_stack, ops);
            else
                ra(a_stack, ops);
        }
        loop_num = b_stack->size;
        while(loop_num--)
        {
            pa(a_stack, b_stack, ops);
        }

        bit_mask <<= 1;
    }
}
