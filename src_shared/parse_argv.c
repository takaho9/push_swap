/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:46:02 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/27 03:03:11 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_option(t_config *config, char *str)
{
	t_sort_type	type;

	if (!ft_strncmp(str, "--bench", 8))
	{
		config->bench = TRUE;
		return (0);
	}
	if (!ft_strncmp(str, "--simple", 9))
		type = SIMPLE;
	else if (!ft_strncmp(str, "--medium", 9))
		type = MEDIUM;
	else if (!ft_strncmp(str, "--complex", 10))
		type = COMPLEX;
	else if (!ft_strncmp(str, "--adaptive", 11))
		type = ADAPTIVE;
	else
		return (ERROR);
	if (config->sort_type != NOT_SPECIFIED)
		return (ERROR);
	config->sort_type = type;
	return (0);
}

static int	parse_one_arg(char *arg, t_stack *stack, t_config *config)
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
		if (!error && tokens[i][0] == '-' && tokens[i][1] == '-')
			error = set_option(config, tokens[i]);
		else if (!error)
			error = set_stack(stack, tokens[i]);
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (error);
}

int	parse_argv(int argc, char **argv, t_stack *stack, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (parse_one_arg(argv[i], stack, config) == ERROR)
			return (ERROR);
		i++;
	}
	return (0);
}
