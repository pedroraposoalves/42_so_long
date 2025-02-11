/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:43:13 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/07 12:19:57 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_option	*new_option(void)
{
	t_option	*conversion;

	conversion = (t_option *)malloc(sizeof(t_option));
	if (!conversion)
		return (NULL);
	conversion->minus = 0;
	conversion->plus = 0;
	conversion->space = 0;
	conversion->cardinal = 0;
	conversion->zero = 0;
	conversion->dot = 0;
	conversion->width = 0;
	conversion->precision = 0;
	conversion->type = '\0';
	return (conversion);
}

void	write_flag(t_option *conv, char flag)
{
	if (flag == '-')
		conv->minus = 1;
	else if (flag == '+')
		conv->plus = 1;
	else if (flag == ' ')
		conv->space = 1;
	else if (flag == '#')
		conv->cardinal = 1;
	else if (flag == '0')
		conv->zero = 1;
}

int	write_precision_width(t_option *conv, int v)
{
	int	res;

	if (conv->dot == 1)
	{
		conv->precision = v;
		res = ft_number_size((long int) conv->precision);
	}
	else
	{
		conv->width = v;
		res = ft_number_size((long int) conv->width);
	}
	return (res);
}

t_option	*read_option(const char **str, va_list *list)
{
	t_option	*conversion;

	conversion = new_option();
	if (!conversion)
		return (NULL);
	while (**str && conversion->type == '\0')
	{
		if (ft_strchr(CONVERSIONS, **str))
			conversion->type = **str;
		else if (ft_strchr(FLAGS, **str) && conversion->dot == 0)
			write_flag(conversion, **str);
		else if (**str == '.')
			conversion->dot = 1;
		else if (**str == '*')
			write_precision_width(conversion, va_arg(*list, int));
		else
			(*str) += write_precision_width(conversion, ft_atoi(*str)) - 1;
		(*str)++;
	}
	return (conversion);
}

/*void	print_conversion(t_option *p)
{
	printf("\n\n-------------\nminus -> %d\n", p->minus);
	printf("plus -> %d\n", p->plus);
	printf("space -> %d\n", p->space);
	printf("card -> %d\n", p->cardinal);
	printf("zero -> %d\n", p->zero);
	printf("dot -> %d\n", p->dot);
	printf("width -> %d\n", p->width);
	printf("precision -> %d\n", p->precision);
	printf("type -> %c\n", p->type);
}*/
