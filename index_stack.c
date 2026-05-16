/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:16:01 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/16 18:48:55 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_nodes(t_stack *stack)
{
	size_t i;
	size_t index;
	t_node *start;
	t_node *cur;

	start = stack->head;
	while (1)
	{
		cur = start;
		index = 0;
		while (1)
		{
			if (start->value > cur->next->value)
				index++;
			cur = cur->next;
			if (cur == start)
				break ;
		}
		start->index = index;

		start = start->next;
		if (start == stack->head)
			break ;
	}
}