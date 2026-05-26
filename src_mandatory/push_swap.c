/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:07:18 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/27 00:23:51 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sort_type	choose_strategy(t_config *config)
{
	if (config->sort_type == SIMPLE
		|| config->sort_type == MEDIUM
		|| config->sort_type == COMPLEX)
		return (config->sort_type);
	if (config->disorder < 0.2)
		return (SIMPLE);
	if (config->disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

static void	sort(t_stack *a_stack, t_stack *b_stack, t_config *config,
		t_ops *ops)
{
	config->executed = choose_strategy(config);
	if (config->executed == SIMPLE)
		simple_sort(a_stack, b_stack, ops);
	else if (config->executed == MEDIUM)
		medium_sort(a_stack, b_stack, ops);
	else
		complex_sort(a_stack, b_stack, ops);
}

static int	init_all(t_stack **a_stack, t_stack **b_stack, t_config **config,
		t_ops **ops)
{
	*a_stack = init_stack();
	*b_stack = init_stack();
	*config = init_config();
	*ops = init_ops();
	if (!*a_stack || !*b_stack || !*config || !*ops)
		return (ERROR);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	t_config	*config;
	t_ops		*ops;

	if (argc < 2)
		return (0);
	if (init_all(&a_stack, &b_stack, &config, &ops) == ERROR)
		error_exit(a_stack, b_stack, config, ops);
	if (parse_argv(argc, argv, a_stack, config) == ERROR)
		error_exit(a_stack, b_stack, config, ops);
	index_stack(a_stack);
	config->disorder = set_disorder(a_stack);
	if (!is_sorted(a_stack))
		sort(a_stack, b_stack, config, ops);
	if (config->bench)
		display_bench(ops, config);
	cleanup_all(a_stack, b_stack, config, ops);
	return (0);
}
