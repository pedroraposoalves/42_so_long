/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:18:13 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:35:15 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putchar(char c, int len)
{
	while (len-- > 0)
		write (1, &c, 1);
}

int	ft_number_size(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1 + ft_number_size(-n);
	else if (n < 10)
		len = 1;
	else if (n >= 10)
		len = 1 + ft_number_size(n / 10);
	return (len);
}
