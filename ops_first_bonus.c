/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_first_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:41:41 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/25 22:01:37 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_bonus(t_stack *a_stack, t_stack *b_stack)
{
	t_node	*bottom;
	t_node	*node;

	if (!a_stack || !b_stack || b_stack -> size == 0)
		return ;
	node = b_stack -> top;
	if (b_stack -> size == 1)
		b_stack -> top = NULL;
	else
	{
		bottom = b_stack -> top -> prev;
		b_stack -> top = node -> next;
		bottom -> next = b_stack -> top;
		b_stack -> top -> prev = bottom;
	}
	b_stack -> size--;
	pa_back_bonus(a_stack, node);
}

static void	pa_back_bonus(t_stack *a_stack,t_node *node)
{
	t_node	*bottom;

	if (!a_stack || a_stack -> size == 0)
	{
		node -> prev = node;
		node -> next = node;
		a_stack -> top = node;
	}
	else
		a_stack -> top = node_add_prev(a_stack -> top, node);
	a_stack -> size++;
}

void	pb_bonus(t_stack *a_stack, t_stack *b_stack)
{
	t_node	*bottom;
	t_node	*node;

	if (!a_stack || !b_stack || a_stack -> size == 0)
		return ;
	node = a_stack -> top;
	if (a_stack -> size == 1)
		a_stack -> top = NULL;
	else
	{
		bottom = a_stack -> top -> prev;
		a_stack -> top = node -> next;
		bottom -> next = a_stack -> top;
		a_stack -> top -> prev = bottom;
	}
	a_stack -> size--;
	pb_back_bonus(b_stack, node);
}

static void	pb_back_bonus(t_stack *b_stack,t_node *node)
{
	t_node	*bottom;

	if (!b_stack || b_stack -> size == 0)
	{
		node -> prev = node;
		node -> next = node;
		b_stack -> top = node;
	}
	else
		b_stack -> top = node_add_prev(b_stack -> top, node);
	b_stack -> size++;
}
