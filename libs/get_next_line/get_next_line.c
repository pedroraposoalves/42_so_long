/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:08:02 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/02 16:23:17 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

/*
Retorna index do char c na String s, se nao tiver, retorna -1
*/
int	ft_gnl_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
Verifica se buffer tem char c:
	- Se tiver retorna string ate c (inclusive) e remove chars do buffer
	- Se nao tiver, retorna NULL
*/
char	*read_line_from_buffer(char **bf, char c)
{
	char	*line;
	char	*to_free;
	int		c_index;
	int		size;

	if (!bf)
		return (NULL);
	size = ft_gnl_strlen(*bf);
	c_index = ft_gnl_strchr(*bf, c);
	if (c_index == -1)
		return (NULL);
	c_index++;
	line = ft_gnl_substr(*bf, 0, c_index);
	if (size - c_index > 0)
	{
		to_free = *bf;
		*bf = ft_gnl_substr(*bf, c_index, size - c_index);
		free(to_free);
	}
	else
	{
		free(*bf);
		*bf = NULL;
	}
	return (line);
}

/*
Le ficheiro ate \n ou final:
	- Se em algum momento receber um file 
	descriptor invalido, para e limpa buffer
*/
void	ft_read_file_to_buffer(int fd, char **bf)
{
	char	*str_read;
	int		size_read;

	size_read = 1;
	while (size_read > 0 && (int) ft_gnl_strchr(*bf, '\n') < 0)
	{
		str_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str_read)
			break ;
		size_read = read(fd, str_read, BUFFER_SIZE);
		if (size_read <= 0)
		{
			free(str_read);
			if (size_read < 0)
			{
				free(*bf);
				*bf = NULL;
			}
		}
		else
		{
			str_read[size_read] = '\0';
			*bf = ft_gnl_strjoin(*bf, str_read);
		}
	}
}

/*
Verifica se buffer tem \n, se tiver, retorna ate \n e remove chars do buffer
	- Se nao tiver \n tenta ler o ficheiro ate \n ou final e carrega para buffer
Verifica se buffer tem \n se tiver, retorna ate \n e remove chars do buffer
	- se nao tiver retorna buf como line s
*/
char	*get_next_line(int fd)
{
	static char	*remaining_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line_from_buffer(&remaining_buf, '\n');
	if (line == NULL)
	{
		ft_read_file_to_buffer(fd, &remaining_buf);
		line = read_line_from_buffer(&remaining_buf, '\n');
		if (line == NULL)
		{
			line = remaining_buf;
			remaining_buf = NULL;
		}
	}
	return (line);
}

/* int	main(void)
{
	char	*s;
	int		fd;
	int		i = 1;

	fd = open("one_line_no_nl.txt", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("|%d: %s|", i++,s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	//check_leaks();
	return (0);
} */
