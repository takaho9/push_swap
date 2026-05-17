/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 06:14:16 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 15:39:45 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_specifier(va_list ap, char spec)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (spec == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (ft_puthex((unsigned long)va_arg(ap, unsigned int),
				spec == 'X'));
	else if (spec == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (spec == '%')
		return (ft_putchar('%'));
	return (ERROR);
}

int	ft_vprintf(const char *fmt, va_list ap)
{
	int	count;
	int	ret;

	count = 0;
	while (*fmt)
	{
		if (*fmt != '%')
			ret = ft_putchar(*fmt);
		else if (!*++fmt)
			return (ERROR);
		else
			ret = ft_handle_specifier(ap, *fmt);
		if (ret < 0)
			return (ERROR);
		count += ret;
		fmt++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, fmt);
	ret = ft_vprintf(fmt, ap);
	va_end(ap);
	return (ret);
}
