/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmds_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:24:54 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/26 11:24:18 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	lose(t_map *map_d)
{
	static int	t;

	t++;
	mlx_put_image_to_window(map_d->mlx_p,
		map_d->win_p, map_d->img.lose, 0, 0);
	if (t > 100)
	{
		mlx_loop_end(map_d->mlx_p);
		t = 0;
	}
	free(map_d->s_steps);
	return (0);
}

int	win(t_map *map_d)
{
	static int	t;

	t++;
	mlx_put_image_to_window(map_d->mlx_p,
		map_d->win_p, map_d->img.win, 0, 0);
	if (t > 100)
		mlx_loop_end(map_d->mlx_p);
	return (0);
}

int	game_over_x(t_map *map_d)
{
	int	i;

	i = 0;
	i = 0;
	free_game(map_d);
	while (map_d->map[i])
	{
		free(map_d->map[i]);
		i++;
	}
	free(map_d->s_steps);
	free(map_d->map);
	free(map_d);
	ft_putstr_fd("\nGAMOVER!\n", 1);
	exit(0);
	return (0);
}

int	game_over(t_map *map_d, int flag)
{
	int	i;

	if (flag == 1)
	{
		mlx_loop_hook(map_d->mlx_p, lose, map_d);
		mlx_loop(map_d->mlx_p);
	}
	if (flag == 2)
	{
		mlx_loop_hook(map_d->mlx_p, win, map_d);
		mlx_loop(map_d->mlx_p);
	}
	i = 0;
	free_game(map_d);
	while (map_d->map[i])
	{
		free(map_d->map[i]);
		i++;
	}
	free(map_d->map);
	free(map_d);
	ft_putstr_fd("\nGAMOVER!\n", 1);
	exit(0);
	return (0);
}
