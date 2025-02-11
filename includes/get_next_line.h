/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:47:23 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/07 12:18:52 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_gnl_strlen(const char *s);
char	*ft_gnl_strdup(const char *src);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	ft_read_file_to_buffer(int fd, char **bf);
char	*read_line_from_buffer(char **bf, char c);
int		ft_gnl_strchr(const char *s, char c);

#endif
