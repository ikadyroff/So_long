/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:46:31 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/15 16:25:05 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	go_up(t_map *map_data)
{
	map_data->map[map_data->p_pos.y - 1][map_data->p_pos.x] = 'P';
	map_data->map[map_data->p_pos.y][map_data->p_pos.x] = '0';
	map_data->p_pos.y--;
	plus_step(map_data);
}

void	go_down(t_map *map_data)
{
	map_data->map[map_data->p_pos.y + 1][map_data->p_pos.x] = 'P';
	map_data->map[map_data->p_pos.y][map_data->p_pos.x] = '0';
	map_data->p_pos.y++;
	plus_step(map_data);
}

void	go_left(t_map *map_data)
{
	map_data->map[map_data->p_pos.y][map_data->p_pos.x - 1] = 'P';
	map_data->map[map_data->p_pos.y][map_data->p_pos.x] = '0';
	map_data->p_pos.x--;
	plus_step(map_data);
}

void	go_right(t_map *map_data)
{
	map_data->map[map_data->p_pos.y][map_data->p_pos.x + 1] = 'P';
	map_data->map[map_data->p_pos.y][map_data->p_pos.x] = '0';
	map_data->p_pos.x++;
	plus_step(map_data);
}
