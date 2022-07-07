/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:45:33 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/28 12:42:40 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	steps_rendering(t_map *map_d)
{
	mlx_string_put(map_d->mlx_p, map_d->win_p, 30, 30, 0xff00, "Steps:");
	mlx_string_put(map_d->mlx_p, map_d->win_p, 90, 30, 0xff00, map_d->s_steps);
	free(map_d->s_steps);
}

void	moves(t_map *map_d, int *obj, int *en, int *anm)
{
	if (*anm > 20)
	{
		sprot_a_i(map_d);
		*anm = 0;
	}
	if (*en > 25)
	{
		sprot_anim(map_d);
		*en = 0;
	}
	if (*obj > 35)
	{
		beer_anim(map_d);
		*obj = 0;
	}
}

void	ptr_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_game(t_map *map_d)
{
	mlx_destroy_image(map_d->mlx_p, map_d->img.wall);
	mlx_destroy_image(map_d->mlx_p, map_d->img.floor);
	mlx_destroy_image(map_d->mlx_p, map_d->img.player);
	mlx_destroy_image(map_d->mlx_p, map_d->img.player_s);
	mlx_destroy_image(map_d->mlx_p, map_d->img.player_w);
	mlx_destroy_image(map_d->mlx_p, map_d->img.player2);
	mlx_destroy_image(map_d->mlx_p, map_d->img.player2_s);
	mlx_destroy_image(map_d->mlx_p, map_d->img.player2_w);
	mlx_destroy_image(map_d->mlx_p, map_d->img.objects);
	mlx_destroy_image(map_d->mlx_p, map_d->img.objects2);
	mlx_destroy_image(map_d->mlx_p, map_d->img.exit);
	mlx_destroy_image(map_d->mlx_p, map_d->img.so_long);
	mlx_destroy_image(map_d->mlx_p, map_d->img.enemy2);
	mlx_destroy_image(map_d->mlx_p, map_d->img.enemy);
	mlx_destroy_image(map_d->mlx_p, map_d->img.win);
	mlx_destroy_image(map_d->mlx_p, map_d->img.lose);
	mlx_destroy_window(map_d->mlx_p, map_d->win_p);
	// ptr_free(&map_d->mlx_p);
}
