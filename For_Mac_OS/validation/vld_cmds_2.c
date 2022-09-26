/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_cmds_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:41:31 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/28 12:18:58 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	n_to_0(char **arr, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '\n')
				arr[i][j] = '\0';
			j++;
		}
		i++;
	}
}

char	**get_arr(char **argv, int x, int y)
{
	int		fd;
	int		i;
	char	**arr;

	arr = malloc((sizeof(char) * (x + 1)) * y);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < y)
	{
		arr[i] = get_next_line(fd);
		i++;
	}
	n_to_0(arr, y);
	return (arr);
}

void	perimtr_check(char **arr, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (arr[i][j])
		{
			if (i == 0 && arr[i][j] != '1')
				prmtr_error(arr, y);
			if (arr[i][0] != '1' || arr[i][x - 1] != '1')
				prmtr_error(arr, y);
			if (i == (y - 1) && arr[i][j] != '1')
				prmtr_error(arr, y);
			j++;
		}
		i++;
	}
}

void	e_p_c_check(int p_cntr, int e_cntr, char **map, int y)
{
	int	c_cntr;
	int	i;
	int	j;

	c_cntr = 0;
	i = -1;
	while (++i < y)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c_cntr++;
			j++;
		}
	}
	if (p_cntr > 1 || p_cntr < 1)
		symbols_error(map, y);
	if (e_cntr < 1)
		symbols_error(map, y);
	if (c_cntr < 1)
		symbols_error(map, y);
}

void	symbols_check(char **map, int y)
{
	int	i;
	int	j;
	int	p_counter;
	int	e_counter;

	e_counter = 0;
	p_counter = 0;
	i = -1;
	while (++i < y)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' &&
				map[i][j] != 'E' && map[i][j] != 'P')
				symbols_error(map, y);
			if (map[i][j] == 'P')
				p_counter++;
			if (map[i][j] == 'E')
				e_counter++;
			j++;
		}
	}
	e_p_c_check(p_counter, e_counter, map, y);
}
