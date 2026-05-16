/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_former_ran.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:08:21 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/16 17:23:37 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	pa(t_node **a_nodes, t_node **b_nodes) // priority high
{
	if (!b_nodes)
		return ;
	
}

// void				pb(t_node **a_nodes, t_node **b_nodes); // priority high

// void				ra(t_node **a_nodes); // priority high


#include <stdio.h>
int	main(void)
{
	t_node	*a_nodes;
	t_node	*b_nodes;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*cur;

	a_nodes = create_elem(5);
	b_nodes = create_elem(5);
	node1 = create_elem(1);
	node2 = create_elem(2);
	node3 = create_elem(3);
	b_nodes -> next = node1;
	node1 -> prev = b_nodes;
	node1 -> next = node2;
	node2 -> prev = node1;
	node2 -> next = node3;
	node3 -> prev = node2;
	node3 -> next = b_nodes;
	b_nodes -> prev = node3;
	cur = b_nodes;
	a_nodes -> prev = a_nodes;
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", cur -> value);
		cur = cur -> next;
	}
	pa(&a_nodes, &b_nodes);
	cur = b_nodes;
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", cur -> value);
		cur = cur -> next;
	}
	printf("\n");
	cur = a_nodes;
	for (int i = 0; i < 2; i++)
	{
		printf("%d\n", cur -> value);
		cur = cur -> next;
	}
}