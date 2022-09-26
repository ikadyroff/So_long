/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_cmds_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:44:47 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/21 12:20:05 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	sym_counter(char **map, int y, char sym)
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
			if (map[i][j] == sym)
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

void	sprot_init(t_map *map_d, int y)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (map_d->map[i][j])
		{
			if (map_d->map[i][j] == 'S')
			{
				map_d->s_pos[n].x = j;
				map_d->s_pos[n].y = i;
				n++;
			}
			j++;
		}
		i++;
	}
}

void	init_struct(t_map *map_d, int x, int y)
{
	t_position	p_pos;

	p_pos = get_pos(map_d->map, y);
	map_d->height = y * 64;
	map_d->lenght = x * 64;
	map_d->current_score = 0;
	map_d->score = sym_counter(map_d->map, y, 'C');
	map_d->s_num = sym_counter(map_d->map, y, 'S');
	map_d->p_pos = p_pos;
	map_d->mlx_p = mlx_init();
	map_d->win_p = mlx_new_window(map_d->mlx_p, (map_d->lenght), \
									(map_d->height), "so_long");
	sprot_init(map_d, y);
}
