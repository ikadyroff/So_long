/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:45:06 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/26 16:26:58 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprot_up(t_map *map_d)
{
	int	i;

	i = 0;
	while (i < map_d->s_num)
	{
		if (map_d->map[map_d->s_pos[i].y - 1][map_d->s_pos[i].x] == '0')
		{
			map_d->map[map_d->s_pos[i].y - 1][map_d->s_pos[i].x] = 'S';
			map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x] = '0';
			map_d->s_pos[i].y--;
		}
		else if (map_d->map[map_d->s_pos[i].y - 1][map_d->s_pos[i].x] == 'P')
			game_over(map_d, 1);
		i++;
	}
}

void	sprot_down(t_map *map_d)
{
	int	i;

	i = -1;
	while (++i < map_d->s_num)
	{
		if (map_d->map[map_d->s_pos[i].y + 1][map_d->s_pos[i].x] == '0')
		{
			map_d->map[map_d->s_pos[i].y + 1][map_d->s_pos[i].x] = 'S';
			map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x] = '0';
			map_d->s_pos[i].y++;
		}
		else if (map_d->map[map_d->s_pos[i].y + 1][map_d->s_pos[i].x] == 'P')
			game_over(map_d, 1);
	}
}

void	sprot_left(t_map *map_d)
{
	int	i;

	i = -1;
	while (++i < map_d->s_num)
	{
		if (map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x - 1] == '0')
		{
			map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x - 1] = 'S';
			map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x] = '0';
			map_d->s_pos[i].x--;
		}
		else if (map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x - 1] == 'P')
			game_over(map_d, 1);
	}
}

void	sprot_right(t_map *map_d)
{
	int	i;

	i = -1;
	while (++i < map_d->s_num)
	{
		if (map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x + 1] == '0')
		{
			map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x + 1] = 'S';
			map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x] = '0';
			map_d->s_pos[i].x++;
		}
		else if (map_d->map[map_d->s_pos[i].y][map_d->s_pos[i].x + 1] == 'P')
			game_over(map_d, 1);
	}
}
