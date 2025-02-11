/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:46:43 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:37:55 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	verif_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (len);
}

static void	ft_putnbr_base_rec(unsigned long nbr, char *base, int size)
{
	if (nbr < (unsigned long) size)
		write(1, &base[nbr], 1);
	else
	{
		ft_putnbr_base_rec(nbr / size, base, size);
		write(1, &base[nbr % size], 1);
	}
}

void	ft_putnbr_base(long nbr, char *base)
{
	int	len_base;

	len_base = verif_base(base);
	if (len_base > 0)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			write(1, "-", 1);
		}
		ft_putnbr_base_rec(nbr, base, len_base);
	}
}

int	ft_putnbr_base_len(long nbr, char *base)
{
	int	len_base;
	int	size;

	size = 0;
	len_base = verif_base(base);
	if (len_base > 0)
	{
		if (nbr == 0)
			return (1);
		if (nbr < 0)
		{
			nbr = -nbr;
			size++;
		}
		while (nbr > 0)
		{
			nbr /= len_base;
			size++;
		}
	}
	return (size);
}
