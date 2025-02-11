/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:36:26 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:31:09 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ps;
	char		*pd;
	size_t		i;

	if (!dest && !src)
		return (dest);
	ps = (char *) src;
	pd = (char *) dest;
	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dest);
}
