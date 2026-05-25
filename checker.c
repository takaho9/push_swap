/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:22:09 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/25 18:08:21 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_ops(t_stack *a_stack, t_stack *b_stack)
{
	
}

void	read_and_execute_ops(t_stack *a_stack, t_stack *b_stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		
	}
}

int	main(int argc, char* argv[])
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	t_config	*config;

	a_stack = init_stack();
	b_stack = init_stack();
	config = init_config();
	parse_argv(argc, argv, a_stack, config);
	
}


int	parse_argv(int argc, char **argv, t_stack *stack, t_config *config)

typedef struct s_config
{
	t_sort_type		sort_type;
	t_bool			bench;
	float			disorder;
}					t_config;
