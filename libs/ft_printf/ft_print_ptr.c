/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:07:05 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:33:16 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	print_ptr(t_option *option, long long lg, int len, int width)
{
	if (option->minus != 1)
	{
		ft_putchar(' ', width - len);
		if (lg == 0 && len == 5)
			write(1, "(nil)", 5);
		else
		{
			write(1, "0x", 2);
			ft_putnbr_base(lg, HEX_BASE);
		}
	}
	else
	{
		if (lg == 0 && len == 5)
			write(1, "(nil)", 5);
		else
		{
			write(1, "0x", 2);
			ft_putnbr_base(lg, HEX_BASE);
		}
		ft_putchar(' ', width - len);
	}
}

void	ft_print_ptr(t_option *option, void *p, int *res)
{
	int				width;
	int				len;
	long long		lg;

	width = 0;
	lg = (unsigned long) p;
	width = option->width;
	if (p == NULL)
		len = 5;
	else
		len = ft_putnbr_base_len(lg, HEX_BASE) + 2;
	print_ptr(option, lg, len, width);
	(*res) += len;
	if (width > len)
		(*res) += width - len;
}
