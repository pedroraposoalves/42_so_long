/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:56:54 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:34:17 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	print_variable(t_option	*option, va_list *list, int *res)
{
	char	type;

	type = option->type;
	if (type == '%')
		ft_print_module(res);
	else if (type == 'c')
		ft_print_char(option, va_arg(*list, int), res);
	else if (type == 's')
		ft_print_str(option, va_arg(*list, char *), res);
	else if (type == 'p')
		ft_print_ptr(option, va_arg(*list, void *), res);
	else if (type == 'd' || type == 'i')
		ft_print_dig(option, va_arg(*list, int), res);
	else if (type == 'u')
		ft_print_udig(option, va_arg(*list, unsigned int), res);
	else if (type == 'x')
		ft_print_hex(option, va_arg(*list, unsigned int), res);
	else if (type == 'X')
		ft_print_hex(option, va_arg(*list, unsigned int), res);
}

static int	check_option(const char **str)
{
	char	c;

	c = **str;
	(*str)++;
	if (c != '%')
		write(1, &c, 1);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	t_option	*option;
	int			res;

	res = 0;
	va_start(list, str);
	while (*str)
	{
		if (check_option(&str))
			res++;
		else
		{
			option = read_option(&str, &list);
			if (option)
			{
				print_variable(option, &list, &res);
				free(option);
			}
		}
	}
	va_end(list);
	return (res);
}
