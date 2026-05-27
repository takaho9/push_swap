/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:11:43 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/27 15:12:57 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *a_stack, t_ops *ops)
{
	size_t	first;
	size_t	second;
	size_t	third;

	first = a_stack -> top -> index;
	second = a_stack -> top -> next -> index;
	third = a_stack -> top -> prev -> index;
	if (first > second && first > third)
		ra(a_stack, ops);
	else if (second > first && second > third)
		rra(a_stack, ops);
	if (a_stack -> top -> index > a_stack -> top -> next -> index)
		sa(a_stack, ops);
}

static void	sort_4(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	while (a_stack -> top -> index != 0)
		ra(a_stack, ops);
	pb(a_stack, b_stack, ops);
	sort_3(a_stack, ops);
	pa(a_stack, b_stack, ops);
}

static void	sort_5(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	while (a_stack -> top -> index != 0)
		ra(a_stack, ops);
	pb(a_stack, b_stack, ops);
	while (a_stack -> top -> index != 1)
		ra(a_stack, ops);
	pb(a_stack, b_stack, ops);
	sort_3(a_stack, ops);
	pa(a_stack, b_stack, ops);
	pa(a_stack, b_stack, ops);
}

void	less_than_or_e_5(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (a_stack -> size == 5)
		sort_5(a_stack, b_stack, ops);
	else if (a_stack -> size == 4)
		sort_4(a_stack, b_stack, ops);
	else if (a_stack -> size == 3)
		sort_3(a_stack, ops);
	else if (a_stack -> size == 2)
		sa(a_stack, ops);
}
