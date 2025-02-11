/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:36:26 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 16:30:27 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	srcsize;
	unsigned int	i;

	srcsize = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && *(src + i) != '\0')
		{
			dest[i] = src[i];
			i ++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}
