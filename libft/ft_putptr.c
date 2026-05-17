/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 06:13:16 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 15:41:38 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	size_t	count;
	int		ret;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	ret = ft_putstr("0x");
	if (ret < 0)
		return (ERROR);
	count += ret;
	ret = ft_puthex((unsigned long)ptr, 0);
	if (ret < 0)
		return (ERROR);
	count += ret;
	return (count);
}
