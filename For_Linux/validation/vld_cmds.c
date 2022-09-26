/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:31:45 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/15 22:06:32 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_y(char **argv)
{
	int		fd;
	int		y;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		y++;
		if (!str)
			break ;
		free(str);
	}
	close(fd);
	return (y - 1);
}

int	get_x(char **argv, int y)
{
	int		fd;
	int		x;
	char	*str;
	int		i;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (0);
	x = ft_strlen(str);
	free(str);
	close(fd);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < y)
	{
		str = get_next_line(fd);
		free(str);
		i++;
	}
	close(fd);
	return (x - 1);
}

void	rctngl_check(int y, int *str_lens)
{
	int	i;

	i = 0;
	while (i < y - 1)
	{
		if (str_lens[i] != str_lens[i + 1])
		{
			if ((i + 1) == y)
				break ;
			free (str_lens);
			error_rctngl();
			break ;
		}
		i++;
	}
}

void	is_rectangle(char **argv, int y)
{
	int		fd;
	int		*str_lens;
	char	*str;
	int		i;

	str_lens = (int *)malloc(sizeof(int *) * y);
	if (str_lens == NULL)
		return ;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < y)
	{
		str = get_next_line(fd);
		str_lens[i] = (ft_strlen(str) - 1);
		if (i == (y - 1))
			str_lens[i] = (str_lens[i] + 1);
		free(str);
		i++;
	}
	close(fd);
	rctngl_check(y, str_lens);
	free(str_lens);
}
