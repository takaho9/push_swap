/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:07:18 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/25 21:53:48 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	set_disorder(config);
	sort(a_stack, b_stack, config, ops);
	if (config->bench)
		display_bench(ops, config);
	return (0);
}

static void	sort(t_stack *a_stack, t_stack *b_stack, t_config *config, t_ops *ops)
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
			simple_sort(a_stack, b_stack);
		else if (config->disorder < 0.5)
			medium_sort(a_stack, b_stack);
		else
			complex_sort(a_stack, b_stack);
	}
}
