/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:43:49 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:33:23 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	print_plus_or_space(t_option *option)
{
	if (option->plus)
		write(1, "+", 1);
	else if (option->space)
		write(1, " ", 1);
}

static void	ft_print_zero_and_precision(t_option *option, int size)
{
	if (option->zero == 1 && option->precision == 0 && option -> dot != 1)
	{
		print_plus_or_space(option);
		ft_putchar('0', size);
	}
	else
	{
		ft_putchar(' ', size);
		print_plus_or_space(option);
	}
}

static void	print_udig(t_option *option, unsigned int n, int len, int size)
{
	int	width;

	width = option->width;
	if (option->minus != 1)
	{
		ft_print_zero_and_precision(option, width - len);
		ft_putchar('0', option->precision - size);
		if (!(option -> dot == 1 && n == 0))
			ft_putnbr_base(n, DEC_BASE);
	}
	else
	{
		ft_putchar('0', option->precision - size);
		if (!(option -> dot == 1 && n == 0))
			ft_putnbr_base(n, DEC_BASE);
		ft_putchar(' ', width - len);
	}
}

void	ft_print_udig(t_option *option, unsigned int n, int *res)
{
	int	width;
	int	len;
	int	n_size;

	n_size = 0;
	width = option->width;
	if (!(option -> dot == 1 && n == 0))
		n_size = ft_putnbr_base_len(n, DEC_BASE);
	len = n_size;
	if (option->precision > len)
		len = option->precision;
	print_udig(option, n, len, n_size);
	(*res) += len;
	if (width > len)
		(*res) += width - len;
}
