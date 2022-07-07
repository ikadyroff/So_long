/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:06:58 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/27 16:08:42 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_over(t_map *map_d)
{
	int	i;

	i = 0;
	while (map_d->map[i])
	{
		free(map_d->map[i]);
		i++;
	}
	free(map_d->map);
	free(map_d);
	free_game(map_d);
	ft_putstr_fd("\nGAMOVER!\n", 1);
	exit(0);
	return (0);
}

void	plus_step(t_map *map_d)
{
	map_d->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(map_d->steps, 1);
	ft_putstr_fd("\n", 1);
}

void	put_img_2_win(t_map *map_d, int x, int y)
{
	if (map_d->map[y][x] == '1')
		mlx_put_image_to_window(map_d->mlx_p, map_d->win_p,
			map_d->img.wall, x * 64, y * 64);
	else if (map_d->map[y][x] == '0')
		mlx_put_image_to_window(map_d->mlx_p, map_d->win_p,
			map_d->img.floor, x * 64, y * 64);
	else if (map_d->map[y][x] == 'P')
		mlx_put_image_to_window(map_d->mlx_p, map_d->win_p,
			map_d->img.player, x * 64, y * 64);
	else if (map_d->map[y][x] == 'E')
		mlx_put_image_to_window(map_d->mlx_p, map_d->win_p,
			map_d->img.exit, x * 64, y * 64);
	else if (map_d->map[y][x] == 'C')
		mlx_put_image_to_window(map_d->mlx_p, map_d->win_p,
			map_d->img.objects, x * 64, y * 64);
}

int	map_rendering(t_map *map_d)
{	
	int	x;
	int	y;

	y = 0;
	while (y < map_d->height / 64)
	{
		x = 0;
		while (map_d->map[y][x])
		{
			put_img_2_win(map_d, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	keys(int key, t_map *map_d)
{
	if (key == UP)
		move_player_up(map_d);
	else if (key == DOWN)
		move_player_down(map_d);
	else if (key == LEFT)
		move_player_left(map_d);
	else if (key == RIGHT)
		move_player_right(map_d);
	else if (key == ESC)
		game_over(map_d);
	map_rendering(map_d);
	return (0);
}
