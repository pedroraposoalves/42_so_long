/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:07:05 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:33:20 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_putstr(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i] && i < size)
		write(1, &str[i++], 1);
}

int	ft_calc_len(t_option *option, char **str)
{
	int	len;

	if (!(*str))
	{
		*str = "(null)\0";
		len = 6;
		if (option -> dot && option->width > 0
			&& option->precision > option->width)
			len = 6;
		else if (option -> dot && (option->precision < len))
			len = 0;
		else if (option -> dot && option->minus == 1)
			len = 6;
		else if (option -> dot && option->width > 0)
			len = 6;
		else if (option -> dot)
			len = option->precision;
	}
	else
	{
		len = ft_strlen(*str);
		if (option -> dot && option->precision < len)
			len = option->precision;
	}
	return (len);
}

void	ft_print_str(t_option *option, char *str, int *res)
{
	int	width;
	int	len;

	width = option->width;
	len = ft_calc_len(option, &str);
	if (option->minus != 1)
	{
		ft_putchar(' ', width - len);
		ft_putstr(str, len);
	}
	else
	{
		ft_putstr(str, len);
		ft_putchar(' ', width - len);
	}
	(*res) += len;
	if (width > len)
		(*res) += width - len;
}
