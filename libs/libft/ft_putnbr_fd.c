/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:36:26 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:30:52 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(long int n, int fd)
{
	char		c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	c = (n % 10) + '0';
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
	else
		write(fd, &c, 1);
}
