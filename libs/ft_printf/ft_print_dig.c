/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:43:49 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:33:08 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_size_num_flags_precision(t_option *option, int n)
{
	int	res;

	res = 0;
	if (!(option -> dot == 1 && n == 0))
		res = ft_number_size(n);
	if (n < 0)
	{
		if (option->precision > (res - 1))
			res = option->precision + 1;
	}
	else
	{
		if (option->precision > res)
			res = option->precision;
	}
	if ((option->plus == 1 && n >= 0) || (option->space == 1 && n >= 0))
		res++;
	return (res);
}

static void	print_plus_or_space(t_option *option, long int *n)
{
	if (*n < 0)
	{
		write(1, "-", 1);
		*n = -(*n);
	}
	else if (option->plus)
		write(1, "+", 1);
	else if (option->space)
		write(1, " ", 1);
}

static void	ft_print_zero_and_precision(t_option *option, int size,
										long int *n)
{
	if (option->zero == 1 && (option->precision != 0 || option -> dot == 0)
		&& !(option->precision > 0 || option -> dot == 1))
	{
		print_plus_or_space(option, n);
		ft_putchar('0', size);
	}
	else
	{
		ft_putchar(' ', size);
		print_plus_or_space(option, n);
	}
}

static void	ft_print_precision(t_option *option, int n)
{
	int	n_size;

	n_size = 0;
	if (!((option -> dot == 1 && n == 0)
			&& (option -> dot == 1 && option -> precision > 0)))
		n_size = ft_number_size(n);
	if (n < 0)
		ft_putchar('0', option->precision - n_size + 1);
	else
		ft_putchar('0', option->precision - n_size);
}

void	ft_print_dig(t_option *option, int n, int *res)
{
	int			width;
	int			len;
	long int	nbr;

	nbr = n;
	width = option->width;
	len = ft_size_num_flags_precision(option, nbr);
	if (option->minus != 1)
	{
		ft_print_zero_and_precision(option, width - len, &nbr);
		ft_print_precision(option, nbr);
		if (!(option -> dot == 1 && nbr == 0))
			ft_putnbr_fd(nbr, 1);
	}
	else
	{
		print_plus_or_space(option, &nbr);
		ft_print_precision(option, nbr);
		if (!(option -> dot == 1 && nbr == 0))
			ft_putnbr_fd(nbr, 1);
		ft_putchar(' ', width - len);
	}
	(*res) += len;
	if (width > len)
		(*res) += width - len;
}
