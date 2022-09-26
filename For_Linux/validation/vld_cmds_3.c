/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_cmds_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:44:47 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/15 16:25:43 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	c_counter(char **map, int y)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

t_position	get_pos(char **map, int y)
{
	t_position	pos;

	pos.y = 0;
	while (pos.y < y)
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'P')
			{
				return (pos);
				break ;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

void	free_map(char **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	init_struct(t_map *map_d, int x, int y)
{
	int			c;
	t_position	p_pos;

	p_pos = get_pos(map_d->map, y);
	c = c_counter(map_d->map, y);
	map_d->height = y * 64;
	map_d->lenght = x * 64;
	map_d->current_score = 0;
	map_d->score = c;
	map_d->p_pos = p_pos;
	map_d->mlx_p = mlx_init();
	map_d->win_p = mlx_new_window(map_d->mlx_p, (map_d->lenght), \
									(map_d->height), "so_long");
}
