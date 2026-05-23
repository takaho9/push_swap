/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:59:54 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/23 20:01:22 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ceil_sqrt(size_t n)
{
	size_t	i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

size_t	ceil(size_t	dividend, size_t divisor)
{
	size_t	i;

	i = 0;
	if (dividend % divisor > 0)
		return(dividend / divisor + 1);
	return (dividend / divisor);
}
