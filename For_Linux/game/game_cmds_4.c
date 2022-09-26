/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:45:33 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/15 16:25:18 by wlouveni         ###   ########.fr       */
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
	mlx_destroy_image(map_d->mlx_p, map_d->img.exit);
	mlx_destroy_image(map_d->mlx_p, map_d->img.floor);
	mlx_destroy_image(map_d->mlx_p, map_d->img.objects);
	mlx_destroy_image(map_d->mlx_p, map_d->img.player);
	mlx_destroy_image(map_d->mlx_p, map_d->img.so_long);
	mlx_destroy_image(map_d->mlx_p, map_d->img.wall);
	mlx_destroy_window(map_d->mlx_p, map_d->win_p);
	mlx_destroy_display(map_d->mlx_p);
	ptr_free(&map_d->mlx_p);
}
