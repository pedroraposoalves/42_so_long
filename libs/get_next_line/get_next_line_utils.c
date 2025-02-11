/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:08:02 by pemirand          #+#    #+#             */
/*   Updated: 2024/09/24 18:10:29 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int	ft_gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strdup(const char *src)
{
	int		len;
	int		i;
	char	*s;

	len = ft_gnl_strlen(src);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_gnl_strjoin_valid(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (ft_gnl_strdup(""));
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	return (NULL);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*res;
	int		i;

	res = ft_gnl_strjoin_valid(s1, s2);
	if (res)
		return (res);
	s1_len = (int) ft_gnl_strlen(s1);
	s2_len = (int) ft_gnl_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	res[s1_len + s2_len] = '\0';
	i = 0;
	while (i < s1_len || i < s2_len)
	{
		if (i < s1_len)
			res[i] = s1[i];
		if (i++ < s2_len)
			res[s1_len + (i - 1)] = s2[i - 1];
	}
	free(s1);
	free(s2);
	return (res);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;
	unsigned int	size;
	unsigned int	i;

	s_len = (unsigned int) ft_gnl_strlen(s);
	substr = NULL;
	size = 0;
	if (s_len > start)
	{
		if (s_len >= start + (unsigned int) len)
			size = (unsigned int) len;
		else
			size = s_len - start;
	}
	substr = (char *)malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	substr[size] = '\0';
	i = 0;
	while (i++ < size)
		substr[i - 1] = s[start + i - 1];
	return (substr);
}
