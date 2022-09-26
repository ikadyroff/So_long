/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:46:31 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/21 16:16:00 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	go_up(t_map *map_d)
{
	map_d->map[map_d->p_pos.y - 1][map_d->p_pos.x] = 'P';
	map_d->map[map_d->p_pos.y][map_d->p_pos.x] = '0';
	map_d->p_pos.y--;
	if (map_d->steps % 2 == 0)
		map_d->img.player_t = map_d->img.player_w;
	if (map_d->steps % 2 != 0)
		map_d->img.player_t = map_d->img.player2_w;
	plus_step(map_d);
}

void	go_down(t_map *map_d)
{
	map_d->map[map_d->p_pos.y + 1][map_d->p_pos.x] = 'P';
	map_d->map[map_d->p_pos.y][map_d->p_pos.x] = '0';
	map_d->p_pos.y++;
	if (map_d->steps % 2 == 0)
		map_d->img.player_t = map_d->img.player_s;
	if (map_d->steps % 2 != 0)
		map_d->img.player_t = map_d->img.player2_s;
	plus_step(map_d);
}

void	go_left(t_map *map_d)
{
	map_d->map[map_d->p_pos.y][map_d->p_pos.x - 1] = 'P';
	map_d->map[map_d->p_pos.y][map_d->p_pos.x] = '0';
	map_d->p_pos.x--;
	if (map_d->steps % 2 == 0)
		map_d->img.player_t = map_d->img.player;
	if (map_d->steps % 2 != 0)
		map_d->img.player_t = map_d->img.player2;
	plus_step(map_d);
}

void	go_right(t_map *map_d)
{
	map_d->map[map_d->p_pos.y][map_d->p_pos.x + 1] = 'P';
	map_d->map[map_d->p_pos.y][map_d->p_pos.x] = '0';
	map_d->p_pos.x++;
	if (map_d->steps % 2 == 0)
		map_d->img.player_t = map_d->img.player;
	if (map_d->steps % 2 != 0)
		map_d->img.player_t = map_d->img.player2;
	plus_step(map_d);
}
