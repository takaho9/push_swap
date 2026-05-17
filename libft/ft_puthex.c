/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 06:13:16 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 15:41:29 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long n, int upper)
{
	char	*hex;
	size_t	count;
	int		ret;

	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		ret = ft_puthex(n >> 4, upper);
		if (ret < 0)
			return (ERROR);
		count += ret;
	}
	ret = ft_putchar(hex[n & 0xf]);
	if (ret < 0)
		return (ERROR);
	count += ret;
	return (count);
}
