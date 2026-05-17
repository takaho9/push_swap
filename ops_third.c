/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_third.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:36:51 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/17 15:52:45 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a_stack, t_ops *ops_stats)
{
	int		tmp_va;
	size_t	tmp_in;

	if (!a_stack || a_stack -> size < 2)
		return ;
	tmp_va = a_stack -> top -> value;
	tmp_in = a_stack -> top -> index;
	a_stack -> top -> value = a_stack -> top -> next -> value;
	a_stack -> top -> index = a_stack -> top -> next -> index;
	a_stack -> top -> next -> value = tmp_va;
	a_stack -> top -> next -> index = tmp_in;
	ops_stats -> sa++;
	ops_stats -> total++;
	ft_printf("sa\n");
}

void	sb(t_stack *b_stack, t_ops *ops_stats)
{
	int		tmp_va;
	size_t	tmp_in;

	if (!b_stack || b_stack -> size < 2)
		return ;
	tmp_va = b_stack -> top -> value;
	tmp_in = b_stack -> top -> index;
	b_stack -> top -> value = b_stack -> top -> next -> value;
	b_stack -> top -> index = b_stack -> top -> next -> index;
	b_stack -> top -> next -> value = tmp_va;
	b_stack -> top -> next -> index = tmp_in;
	ops_stats -> sb++;
	ops_stats -> total++;
	ft_printf("sb\n");
}

void	ss(t_stack *a_stack, t_stack *b_stack, t_ops *ops_stats)
{
	int		tmp_va;
	size_t	tmp_in;

	if (!a_stack || !b_stack || a_stack -> size < 2 || b_stack -> size < 2)
		return ;
	tmp_va = a_stack -> top -> value;
	tmp_in = a_stack -> top -> index;
	a_stack -> top -> value = a_stack -> top -> next -> value;
	a_stack -> top -> index = a_stack -> top -> next -> index;
	a_stack -> top -> next -> value = tmp_va;
	a_stack -> top -> next -> index = tmp_in;
	tmp_va = b_stack -> top -> value;
	tmp_in = b_stack -> top -> index;
	b_stack -> top -> value = b_stack -> top -> next -> value;
	b_stack -> top -> index = b_stack -> top -> next -> index;
	b_stack -> top -> next -> value = tmp_va;
	b_stack -> top -> next -> index = tmp_in;
	ops_stats -> ss++;
	ops_stats -> total++;
	ft_printf("ss\n");
}
