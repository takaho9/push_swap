/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:28:37 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 17:43:11 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->prev = node;
	node->next = node;
	return (node);
}

/* add new node right before cur node, and return new node */
t_node	*node_add_prev(t_node *cur, t_node *new)
{
	t_node	*prev;

	prev = cur->prev;
	cur->prev = new;
	new->next = cur;
	new->prev = prev;
	prev->next = new;
	return (new);
}

/* add new node right after cur node, and return new node */
t_node	*node_add_next(t_node *cur, t_node *new)
{
	t_node	*next;

	next = cur->next;
	cur->next = new;
	new->prev = cur;
	new->next = next;
	next->prev = new;
	return (new);
}

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack -> top = NULL;
	new_stack -> size = 0;
	return (new_stack);
}

t_ops	*init_ops(void)
{
	t_ops	*init_ops;

	init_ops = malloc(sizeof(t_ops));
	if (!init_ops)
		return (NULL);
	init_ops -> sa = 0;
	init_ops -> sb = 0;
	init_ops -> ss = 0;
	init_ops -> pa = 0;
	init_ops -> pb = 0;
	init_ops -> ra = 0;
	init_ops -> rb = 0;
	init_ops -> rr = 0;
	init_ops -> rra = 0;
	init_ops -> rrb = 0;
	init_ops -> rrr = 0;
	init_ops -> total = 0;
	return (init_ops);
}
