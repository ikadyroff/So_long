/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:45:33 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/26 10:44:26 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	mlx_destroy_display(map_d->mlx_p);
	ptr_free(&map_d->mlx_p);
}
