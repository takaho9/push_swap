/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 06:13:16 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 15:41:11 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	size_t	count;
	long	num;
	int		ret;

	count = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		ret = ft_putchar('-');
		if (ret < 0)
			return (ERROR);
		count += ret;
	}
	if (num >= 10)
	{
		ret = ft_putnbr(num / 10);
		if (ret < 0)
			return (ERROR);
		count += ret;
	}
	ret = ft_putchar('0' + num % 10);
	if (ret < 0)
		return (ERROR);
	return (count + ret);
}
