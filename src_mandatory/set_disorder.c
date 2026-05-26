/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:51 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/27 00:26:29 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_mistakes(t_stack *a_stack)
{
	t_node	*node_i;
	t_node	*node_j;
	size_t	i;
	size_t	mistake;

	mistake = 0;
	node_i = a_stack->top;
	i = 0;
	while (i < a_stack->size - 1)
	{
		node_j = node_i->next;
		while (node_j != a_stack->top)
		{
			if (node_i->index > node_j->index)
				mistake++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
		i++;
	}
	return (mistake);
}

double	set_disorder(t_stack *a_stack)
{
	size_t	total_pairs;
	size_t	mistakes;

	if (!a_stack || a_stack->size < 2)
		return (0.0);
	total_pairs = a_stack->size * (a_stack->size - 1) / 2;
	mistakes = count_mistakes(a_stack);
	return ((double)mistakes / (double)total_pairs);
}
