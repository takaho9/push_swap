/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 06:13:16 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/17 15:41:04 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	size_t	len;
	int		ret;

	if (!s)
	{
		ret = write(1, "(null)", 6);
		if (ret < 0)
			return (ERROR);
		return (6);
	}
	len = ft_strlen(s);
	ret = write(1, s, len);
	if (ret < 0)
		return (ERROR);
	return (len);
}
