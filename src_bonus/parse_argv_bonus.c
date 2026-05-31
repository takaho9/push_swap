/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:02:23 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/31 17:04:21 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_one_arg(char *arg, t_stack *stack)
{
	char	**tokens;
	int		i;
	int		error;

	if (*arg == '\0')
		return (ERROR);
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (ERROR);
	i = 0;
	error = 0;
	while (tokens[i])
	{
		if (!error)
			error = set_stack(stack, tokens[i]);
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (error);
}

int	parse_argv_bonus(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (parse_one_arg(argv[i], stack) == ERROR)
			return (ERROR);
		i++;
	}
	return (0);
}
