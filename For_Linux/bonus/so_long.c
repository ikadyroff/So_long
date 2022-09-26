/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:53:48 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/21 16:27:57 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*arg_validation(char **argv)
{
	int		y;
	int		x;
	t_map	*map_d;

	is_ber(argv);
	y = get_y(argv);
	x = get_x(argv, y);
	is_rectangle(argv, y);
	map_d = (t_map *)malloc(sizeof(t_map));
	if (map_d == NULL)
		return (NULL);
	map_d->map = get_arr(argv, x, y);
	perimtr_check(map_d->map, x, y);
	symbols_check(map_d->map, y);
	init_struct(map_d, x, y);
	return (map_d);
}

void	init_sprites(t_map *map_d)
{
	int	w;
	int	h;
	int	is;

	w = 100;
	h = 100;
	is = 800;
	init_img(map_d, w, h, is);
	if (!map_d->img.wall || !map_d->img.floor || !map_d->img.player
		|| !map_d->img.objects || !map_d->img.exit || !map_d->img.so_long)
	{
		ft_putstr_fd("Error!\n", 2);
		ft_putstr_fd("Can't open image\n", 2);
		free(map_d);
		exit(1);
	}
	map_d->img.player_t = map_d->img.player;
	map_d->img.objects_t = map_d->img.objects;
	map_d->img.enemy_t = map_d->img.enemy;
}

void	game(t_map *map_d)
{
	mlx_put_image_to_window(map_d->mlx_p,
		map_d->win_p, map_d->img.so_long, 450, 30);
	mlx_hook(map_d->win_p, 2, 1L << 0, keys, map_d);
	mlx_hook(map_d->win_p, 17, 0, game_over_x, map_d);
	sleep(1);
	mlx_loop_hook(map_d->mlx_p, anim, map_d);
	mlx_loop(map_d->mlx_p);
}

int	main(int argc, char **argv)
{
	t_map	*map_d;

	if (argc == 2)
	{
		map_d = arg_validation(argv);
		init_sprites(map_d);
		game(map_d);
		free(map_d);
	}
	else
		error();
	return (0);
}
