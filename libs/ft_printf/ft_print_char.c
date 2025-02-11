/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:07:05 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:33:05 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_print_char(t_option *option, char c, int *res)
{
	int	width;

	width = option->width;
	if (option->minus != 1)
	{
		ft_putchar(' ', width - 1);
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		ft_putchar(' ', width - 1);
	}
	if (width > 1)
		(*res) += width;
	else
		(*res)++;
}
