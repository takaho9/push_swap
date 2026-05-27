/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:11:43 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/27 14:48:05 by wezhou           ###   ########.fr       */
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
	if (first < second && second > third)
	{
		rra(a_stack, ops);
		sa(a_stack, ops);
	}
	else if (second < first && second < third && third > first)
		sa(a_stack, ops);
	else if (second < first && second < third && third < first)
		rra(a_stack, ops);
	else if (first > second && first > third && third < second)
	{
		sa(a_stack, ops);
		rra(a_stack, ops);
	}
	else
		ra(a_stack, ops);
}

static void	sort_4(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	t_node	*cur;
	size_t	i;

	i = 0;
	cur = a_stack -> top;
	while (i < a_stack -> size)
	{
		if (cur -> index != 0)
			ra(a_stack, ops);
		else
		{
			pb(a_stack, b_stack, ops);
			break;
		}
		i++;
	}
	sort_3(a_stack, ops);
	pa(a_stack, b_stack, ops);
}

static void	sort_5(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	t_node	*cur;
	size_t	i;
	int		min_pushed;

	i = 0;
	min_pushed = 0;
	cur = a_stack -> top;
	while (i < a_stack -> size)
	{
		if (cur -> index != 0 && min_pushed == 0)
			ra(a_stack, ops);
		else if (cur -> index == 0 && min_pushed == 0)
		{
			pb(a_stack, b_stack, ops);
			min_pushed = 1;
		}
		if (cur -> index != 1 && min_pushed == 1)
			ra(a_stack, ops);
		else if (min_pushed == 1)
		{
			pb(a_stack, b_stack, ops);
			break;
		}
		i++;
	}
	sort_3(a_stack, ops);
	pa(a_stack, b_stack, ops);
	pa(a_stack, b_stack, ops);
}

void	less_than_or_e_5(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
{
	if (a_stack -> size == 5)
		sort_5(a_stack, b_stack, ops);
	if (a_stack -> size == 4)
		sort_4(a_stack, b_stack, ops);
	if (a_stack -> size == 3)
		sort_3(a_stack, ops);
	if (a_stack -> size == 2)
		sa(a_stack, ops);
}
