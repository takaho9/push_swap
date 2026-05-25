/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bench.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakemur <ttakemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 22:00:00 by ttakemur          #+#    #+#             */
/*   Updated: 2026/05/16 22:00:00 by ttakemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_disorder(float disorder)
{
	int	total;
	int	whole;
	int	frac;

	total = (int)(disorder * 10000.0f + 0.5f);
	whole = total / 100;
	frac = total % 100;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (frac < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n", 2);
}

static void	put_strategy(t_sort_type type)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (type == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (type == MEDIUM)
		ft_putstr_fd("Medium / O(n log n)\n", 2);
	else if (type == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else if (type == ADAPTIVE)
		ft_putstr_fd("Adaptive / O(n\xe2\x88\x9an)\n", 2);
	else
		ft_putstr_fd("Not specified\n", 2);
}

static void	put_ops_a(t_ops *ops)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(ops->sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(ops->sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(ops->ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(ops->pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(ops->pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	put_ops_b(t_ops *ops)
{
	ft_putstr_fd("[bench] ra:  ", 2);
	ft_putnbr_fd(ops->ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(ops->rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(ops->rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(ops->rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(ops->rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(ops->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	display_bench(t_ops *ops, t_config *config)
{
	put_disorder(config->disorder);
	put_strategy(config->sort_type);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ops->total, 2);
	ft_putstr_fd("\n", 2);
	put_ops_a(ops);
	put_ops_b(ops);
}
