/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 06:13:16 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 15:41:18 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned(unsigned int n)
{
	size_t	count;
	int		ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putunsigned(n / 10);
		if (ret < 0)
			return (ERROR);
		count += ret;
	}
	ret = ft_putchar('0' + n % 10);
	if (ret < 0)
		return (ERROR);
	count += ret;
	return (count);
}
