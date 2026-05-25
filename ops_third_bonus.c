/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_third_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:41:44 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/25 17:42:28 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a_stack, t_ops *ops)
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
	ops -> sa++;
	ops -> total++;
}

void	sb(t_stack *b_stack, t_ops *ops)
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
	ops -> sb++;
	ops -> total++;
}

void	ss(t_stack *a_stack, t_stack *b_stack, t_ops *ops)
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
	ops -> ss++;
	ops -> total++;
}
