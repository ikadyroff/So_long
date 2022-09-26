/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:04:58 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/26 11:21:31 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img(t_map *map_d, int w, int h, int is)
{
	map_d->img.wall = mlx_xpm_file_to_image(map_d->mlx_p, WALL, &w, &h);
	map_d->img.floor = mlx_xpm_file_to_image(map_d->mlx_p, FLOOR, &w, &h);
	map_d->img.player = mlx_xpm_file_to_image(map_d->mlx_p, PLAYER, &w, &h);
	map_d->img.player_s = mlx_xpm_file_to_image(map_d->mlx_p, PLAYER_S, &w, &h);
	map_d->img.player_w = mlx_xpm_file_to_image(map_d->mlx_p, PLAYER_W, &w, &h);
	map_d->img.player2 = mlx_xpm_file_to_image(map_d->mlx_p, PLAYER2, &w, &h);
	map_d->img.player2_s = mlx_xpm_file_to_image(map_d->mlx_p,
			PLAYER2_S, &w, &h);
	map_d->img.player2_w = mlx_xpm_file_to_image(map_d->mlx_p,
			PLAYER2_W, &w, &h);
	map_d->img.objects = mlx_xpm_file_to_image(map_d->mlx_p, OBJECTS, &w, &h);
	map_d->img.objects2 = mlx_xpm_file_to_image(map_d->mlx_p, OBJECTS2, &w, &h);
	map_d->img.exit = mlx_xpm_file_to_image(map_d->mlx_p, EXIT, &w, &h);
	map_d->img.so_long = mlx_xpm_file_to_image(map_d->mlx_p, SO_LONG, &is, &is);
	map_d->img.enemy = mlx_xpm_file_to_image(map_d->mlx_p, ENEMY, &w, &h);
	map_d->img.enemy2 = mlx_xpm_file_to_image(map_d->mlx_p, ENEMY2, &w, &h);
	map_d->img.win = mlx_xpm_file_to_image(map_d->mlx_p, WIN, &w, &h);
	map_d->img.lose = mlx_xpm_file_to_image(map_d->mlx_p, LOSE, &w, &h);
}

void	sprot_a_i(t_map *map_d)
{
	int	i;

	i = rand() % 10;
	if (i == 1 || i == 9)
	{
		sprot_up(map_d);
		sprot_up(map_d);
	}
	if (i == 2 || i == 7)
	{
		sprot_down(map_d);
		sprot_down(map_d);
	}
	if (i == 3 || i == 8 || i == 0)
	{
		sprot_left(map_d);
		sprot_left(map_d);
	}
	if (i == 4 || i == 6 || i == 5)
	{
		sprot_right(map_d);
		sprot_right(map_d);
	}
}

void	sprot_anim(t_map *map_d)
{
	if (map_d->img.enemy_t == map_d->img.enemy)
		(map_d->img.enemy_t = map_d->img.enemy2);
	else if (map_d->img.enemy_t == map_d->img.enemy2)
		(map_d->img.enemy_t = map_d->img.enemy);
}

void	beer_anim(t_map *map_d)
{
	if (map_d->img.objects_t == map_d->img.objects)
		(map_d->img.objects_t = map_d->img.objects2);
	else if (map_d->img.objects_t == map_d->img.objects2)
		(map_d->img.objects_t = map_d->img.objects);
}

void steps_rendering(t_map *map_d)
{
	mlx_string_put(map_d->mlx_p, map_d->win_p, 30, 30, 0xff00, "Steps:");
	mlx_string_put(map_d->mlx_p, map_d->win_p, 70, 30, 0xff00, map_d->s_steps);
	free(map_d->s_steps);
}

int	anim(t_map *map_d)
{
	static int	obj;
	static int	en;
	static int	anm;

	map_d->s_steps = ft_itoa(map_d->steps);
	obj++;
	en++;
	anm++;
	if (anm > 50)
	{
		sprot_a_i(map_d);
		anm = 0;
	}
	if (en > 45)
	{
		sprot_anim(map_d);
		en = 0;
	}
	if (obj > 65)
	{
		beer_anim(map_d);
		obj = 0;
	}
	steps_rendering(map_d);
	map_rendering(map_d);
	return (0);
}
