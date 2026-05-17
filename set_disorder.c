/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:51 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/17 17:14:03 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	set_disorder(t_stack *a_stack)
{
	t_node	*node_i;
	t_node	*node_j;
	size_t	mistake;
	size_t	total_pairs;

	mistake = 0;
	if (!a_stack || a_stack -> size < 2)
		return (0.0);
	total_pairs = (a_stack -> size) * (a_stack -> size - 1) / 2;
	node_i = a_stack -> top;
	return (compute_disorder(a_stack, node_i, node_j, mistake, total_pairs));
}

float	compute_disorder(t_stack *a_stack, t_node *node_i, t_node *node_j, size_t mistake, size_t total_pairs)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (a_stack -> size - 1))
	{
		j = i + 1;
		node_j = node_i -> next;
		while (j < a_stack -> size)
		{
			if (node_i -> index > node_j -> index)
				mistake++;
			node_j = node_j -> next;
			j++;
		}
		node_i = node_i -> next;
		i++;
	}
	return ((float)mistake / (float)total_pairs);
}
