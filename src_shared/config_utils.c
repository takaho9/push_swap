/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:02:26 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/16 21:14:57 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_config	*init_config(void)
{
	t_config *config;
	config = malloc(sizeof(t_config));
	if (!config)
		return (NULL);

	config->bench = FALSE;
	config->disorder = 0;
	config->sort_type = NOT_SPECIFIED;

	return (config);
}
