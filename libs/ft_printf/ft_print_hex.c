/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:43:49 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:33:11 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_print_cardinal(t_option *option)
{
	if (option->cardinal)
	{
		if (option->type == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
}

static int	ft_print_dig_size_without_width(t_option *option, int hex_size)
{
	int	res;

	res = hex_size;
	if (option->cardinal == 1)
		res += 2;
	if (option->precision > res)
		res = option->precision;
	if (option->cardinal == 1 && option->precision + 2 > res)
		res = option->precision + 2;
	return (res);
}

static void	ft_print_cardinal_and_precision(t_option *option, int size)
{
	if (option->zero == 1 && option->precision == 0 && option -> dot != 1)
	{
		ft_print_cardinal(option);
		ft_putchar('0', size);
	}
	else
	{
		ft_putchar(' ', size);
		ft_print_cardinal(option);
	}
}

static void	ft_printhex_stdout(t_option *option, unsigned long long hex,
								int hex_size, int len)
{
	char	*base;
	int		width;

	width = option->width;
	if (option->type == 'x')
		base = HEX_BASE;
	else
		base = HEX_UPPER_BASE;
	if (option->minus != 1)
	{
		ft_print_cardinal_and_precision(option, width - len);
		ft_putchar('0', option->precision - hex_size);
		if (!(option -> dot == 1 && hex == 0))
			ft_putnbr_base(hex, base);
	}
	else
	{
		ft_print_cardinal(option);
		ft_putchar('0', option->precision - hex_size);
		if (!(option -> dot == 1 && hex == 0))
			ft_putnbr_base(hex, base);
		ft_putchar(' ', width - len);
	}
}

void	ft_print_hex(t_option *option, unsigned long long hex, int *res)
{
	int	width;
	int	len;
	int	hex_size;

	hex_size = 0;
	width = option->width;
	if (hex == 0)
		option->cardinal = 0;
	if (!(option -> dot == 1 && hex == 0))
		hex_size = ft_putnbr_base_len(hex, HEX_BASE);
	len = ft_print_dig_size_without_width(option, hex_size);
	ft_printhex_stdout(option, hex, hex_size, len);
	(*res) += len;
	if (width > len)
		(*res) += width - len;
}
