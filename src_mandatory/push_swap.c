/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:07:18 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/25 23:08:10 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack *a_stack, t_stack *b_stack, t_config *config,
		t_ops *ops)
{
	if (config->sort_type == SIMPLE)
		simple_sort(a_stack, b_stack, ops);
	else if (config->sort_type == MEDIUM)
		medium_sort(a_stack, b_stack, ops);
	else if (config->sort_type == COMPLEX)
		complex_sort(a_stack, b_stack, ops);
	else
	{
		if (config->disorder < 0.2)
			simple_sort(a_stack, b_stack, ops);
		else if (config->disorder < 0.5)
			medium_sort(a_stack, b_stack, ops);
		else
			complex_sort(a_stack, b_stack, ops);
	}
}

#include <stdio.h>

// static void	print_stack(t_stack *a_stack)
// {
// 	size_t	i;
// 	t_node	*cur;

// 	cur = a_stack->top;
// 	i = 0;
// 	while (i < a_stack->size)
// 	{
// 		printf("%d\n", cur->value);
// 		i++;
// 		cur = cur->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	t_config	*config;
	t_ops		*ops;

	if (argc < 2)
		return (0);
	b_stack = init_stack();
	a_stack = init_stack();
	ops = init_ops();
	config = init_config();
	parse_argv(argc, argv, a_stack, config);
	index_stack(a_stack);
	config->disorder = set_disorder(a_stack);
	sort(a_stack, b_stack, config, ops);
	if (config->bench)
		display_bench(ops, config);
	return (0);
}
