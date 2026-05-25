/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:44:05 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/25 17:52:12 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a_stack)
{
	t_node	*cur;
	size_t	i;

	if (!a_stack)
		return (0);
	if (a_stack -> size < 2)
		return (1);
	cur = a_stack -> top;
	i = 0;
	while (i < a_stack -> size - 1)
	{
		if (cur -> index > cur -> next -> index)
			return (0);
		cur = cur -> next;
		i++;
	}
	return (1);
}
