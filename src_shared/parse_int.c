/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:00:00 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/26 00:00:00 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_int(const char *s, int *out)
{
	long long	n;
	int			sign;

	n = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (ERROR);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (ERROR);
		n = n * 10 + (*s - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (ERROR);
		s++;
	}
	*out = (int)(n * sign);
	return (0);
}

static int	has_duplicate(t_stack *stack, int num)
{
	t_node	*cur;
	size_t	i;

	if (!stack->top)
		return (0);
	cur = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (cur->value == num)
			return (1);
		cur = cur->next;
		i++;
	}
	return (0);
}

int	set_stack(t_stack *stack, char *str)
{
	int		num;
	t_node	*new;

	if (parse_int(str, &num) == ERROR)
		return (ERROR);
	if (has_duplicate(stack, num))
		return (ERROR);
	new = node_new(num);
	if (!new)
		return (ERROR);
	if (!stack->top)
		stack->top = new;
	else
		node_add_prev(stack->top, new);
	stack->size++;
	return (0);
}
