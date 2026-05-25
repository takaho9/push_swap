/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:22:09 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/25 22:09:20 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

static int	execute_ops(t_stack *a_stack, t_stack *b_stack, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa_bonus(a_stack);
	else if (!ft_strcmp(line, "sb\n"))
		sb_bonus(b_stack);
	else if (!ft_strcmp(line, "ss\n"))
		ss_bonus(a_stack, b_stack);
	else if (!ft_strcmp(line, "ra\n"))
		ra_bonus(a_stack);
	else if (!ft_strcmp(line, "rb\n"))
		rb_bonus(b_stack);
	else if (!ft_strcmp(line, "rr\n"))
		rr_bonus(a_stack, b_stack);
	else if (!ft_strcmp(line, "rra\n"))
		rra_bonus(b_stack);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb_bonus(b_stack);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr_bonus(b_stack);
	else if (!ft_strcmp(line, "pa\n"))
		pa_bonus(b_stack);
	else if (!ft_strcmp(line, "pb\n"))
		pb_bonus(b_stack);
	else
		return (0);
	return (1);
}

static int	read_and_execute_ops(t_stack *a_stack, t_stack *b_stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_ops(a_stack, b_stack, line))
		{
			ft_printf("Error\n");
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char* argv[])
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	t_config	*config;

	if (argc < 2)
		return (0);
	a_stack = init_stack();
	b_stack = init_stack();
	config = init_config();
	if (parse_argv(argc, argv, a_stack, config) == ERROR)
		ft_printf("Error\n");
	if (!read_and_execute_ops(a_stack, b_stack))
		return (0);
	if (is_sorted(a_stack) && b_stack -> size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
