/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:16:01 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/25 23:30:00 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	size_t	index;
	t_node	*start;
	t_node	*cur;

	if (!stack || !stack->top)
		return ;
	start = stack->top;
	while (1)
	{
		cur = start->next;
		index = 0;
		while (cur != start)
		{
			if (start->value > cur->value)
				index++;
			cur = cur->next;
		}
		start->index = index;
		start = start->next;
		if (start == stack->top)
			break ;
	}
}
