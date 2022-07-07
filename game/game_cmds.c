/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:50:50 by wlouveni          #+#    #+#             */
/*   Updated: 2022/05/26 19:21:50 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_playdr_up(t_map *map_d)
{
	if (map_d->map[map_d->p_pos.y - 1][map_d->p_pos.x] == '0')
		go_up(map_d);
	else if (map_d->map[map_d->p_pos.y - 1][map_d->p_pos.x] == 'C')
	{
		go_up(map_d);
		map_d->current_score++;
		map_d->score--;
	}
	else if (map_d->map[map_d->p_pos.y - 1][map_d->p_pos.x] == 'E' &&
			map_d->score == 0)
	{
		go_up(map_d);
		game_over(map_d);
	}
}

void	move_player_down(t_map *map_d)
{
	if (map_d->map[map_d->p_pos.y + 1][map_d->p_pos.x] == '0')
		go_down(map_d);
	else if (map_d->map[map_d->p_pos.y + 1][map_d->p_pos.x] == 'C')
	{
		go_down(map_d);
		map_d->current_score++;
		map_d->score--;
	}
	else if (map_d->map[map_d->p_pos.y + 1][map_d->p_pos.x] == 'E' &&
			map_d->score == 0)
		game_over(map_d);
}

void	move_player_left(t_map *map_d)
{
	if (map_d->map[map_d->p_pos.y][map_d->p_pos.x - 1] == '0')
		go_left(map_d);
	else if (map_d->map[map_d->p_pos.y][map_d->p_pos.x - 1] == 'C')
	{
		go_left(map_d);
		map_d->current_score++;
		map_d->score--;
	}
	else if (map_d->map[map_d->p_pos.y][map_d->p_pos.x - 1] == 'E' &&
			map_d->score == 0)
		game_over(map_d);
}

void	move_player_right(t_map *map_d)
{
	if (map_d->map[map_d->p_pos.y][map_d->p_pos.x + 1] == '0')
		go_right(map_d);
	else if (map_d->map[map_d->p_pos.y][map_d->p_pos.x + 1] == 'C')
	{
		go_right(map_d);
		map_d->current_score++;
		map_d->score--;
	}
	else if (map_d->map[map_d->p_pos.y][map_d->p_pos.x + 1] == 'E' &&
			map_d->score == 0)
		game_over(map_d);
}
