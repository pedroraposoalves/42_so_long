/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:53:41 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/07 12:20:14 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define CONVERSIONS "%cspdiuxX\0"

# define FLAGS "-+ #0\0"

# define HEX_BASE "0123456789abcdef\0"

# define HEX_UPPER_BASE "0123456789ABCDEF\0"

# define DEC_BASE "0123456789\0"

# define LONG_MIN -9223372036854775808
# define LONG_MAX 9223372036854775807

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define UINT_MAX 4294967295

# define ULONG_MAX 18446744073709551615

typedef struct s_option
{
	int		minus;
	int		plus;
	int		space;
	int		cardinal;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	char	type;
}	t_option;

int			ft_printf(const char *str, ...);
t_option	*read_option(const char **str, va_list *list);
//void		print_conversion(t_option *p);
void		ft_print_module(int *res);
void		ft_print_char(t_option *option, char c, int *res);
void		ft_print_str(t_option *option, char *str, int *res);
void		ft_print_ptr(t_option *option, void *p, int *res);
void		ft_print_dig(t_option *option, int n, int *res);
void		ft_print_udig(t_option *option, unsigned int n, int *res);
void		ft_print_hex(t_option *option, unsigned long long hex, int *res);
int			ft_number_size(long long n);
void		ft_putnbr_base(long nbr, char *base);
int			ft_putnbr_base_len(long nbr, char *base);
void		ft_putchar(char c, int len);

#endif
