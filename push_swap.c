/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:07:18 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/16 21:53:48 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_config	*config;
	t_ops		*ops;

	stack_b = init_stack();
	stack_a = init_stack();
    ops = init_ops();
	config = init_config();
	parse_argv(argc, argv, stack_a, config);
	index_stack(stack_a);
	set_disorder(config);
	sort(stack_a, stack_b, config);
	if (config->bench)
		display_bench(ops, config);
	return (0);
}

static void	sort(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
	if (config->sort_type == SIMPLE)
		simple_sort(stack_a, stack_b);
	else if (config->sort_type == MEDIUM)
		medium_sort(stack_a, stack_b);
	else if (config->sort_type == COMPLEX)
		complex_sort(stack_a, stack_b);
	else
	{
		if (config->disorder < 0.2)
			simple_sort(stack_a, stack_b);
		else if (config->disorder < 0.5)
			medium_sort(stack_a, stack_b);
		else
			complex_sort(stack_a, stack_b);
	}
}
