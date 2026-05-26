/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:30:00 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/25 23:30:00 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;
	size_t	i;

	if (!stack)
		return ;
	cur = stack->top;
	i = 0;
	while (i < stack->size)
	{
		next = cur->next;
		free(cur);
		cur = next;
		i++;
	}
	free(stack);
}

void	cleanup_all(t_stack *a_stack, t_stack *b_stack, t_config *config,
		t_ops *ops)
{
	free_stack(a_stack);
	free_stack(b_stack);
	free(config);
	free(ops);
}

void	error_exit(t_stack *a_stack, t_stack *b_stack, t_config *config,
		t_ops *ops)
{
	ft_putstr_fd("Error\n", 2);
	cleanup_all(a_stack, b_stack, config, ops);
	exit(1);
}
