/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:29:27 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/05 13:18:16 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(char *line, int fd)
{
	char	*buffer;
	int		n_bytes;

	n_bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!t_strchr(line, '\n') && n_bytes != 0)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[n_bytes] = '\0';
		line = t_strjn(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*printer(char *static_str)
{
	char	*line;
	int		i;

	i = 0;
	if (static_str[i] == '\0')
		return (0);
	while (static_str[i] && static_str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (static_str[i] && static_str[i] != '\n')
	{
		line[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		line[i] = static_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*trimmer(char *str)
{
	int		i1;
	int		i2;
	char	*line;

	i1 = 0;
	i2 = 0;
	while (str[i1] && str[i1] != '\n')
			i1++;
	if (!str[i1])
	{
		free(str);
		return (NULL);
	}
	line = malloc(sizeof(char) * (t_strlen(str) - i1 + 1));
	if (!line)
		return (NULL);
	i1++;
	while (str[i1])
		line[i2++] = str[i1++];
	line[i2] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_line = reader(static_line, fd);
	if (!static_line)
		return (NULL);
	line = printer(static_line);
	static_line = trimmer(static_line);
	return (line);
}
