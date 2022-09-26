/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:58:58 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/26 11:08:11 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <time.h>
# include "gnl/get_next_line.h"

# define WALL		"textures/wall.xpm"
# define PLAYER		"textures/player.xpm"
# define PLAYER_W	"textures/player_w.xpm"
# define PLAYER_S	"textures/player_s.xpm"
# define PLAYER2	"textures/player2.xpm"
# define PLAYER2_W	"textures/player2_w.xpm"
# define PLAYER2_S	"textures/player2_s.xpm"
# define FLOOR		"textures/floor.xpm"
# define OBJECTS	"textures/objects.xpm"
# define OBJECTS2	"textures/objects2.xpm"
# define EXIT		"textures/exit.xpm"
# define WIN		"textures/win.xpm"
# define LOSE		"textures/lose.xpm"
# define SO_LONG	"textures/so_long.xpm"
# define ENEMY		"textures/enemy.xpm"
# define ENEMY2		"textures/enemy2.xpm"

# define ESC 65307
# define LEFT 97
# define DOWN 115
# define UP 119
# define RIGHT 100

// # define ESC 53
// # define UP	13
// # define DOWN 1
// # define LEFT 0
// # define RIGHT 2

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_texture
{
	void	*wall;
	void	*exit;
	void	*objects;
	void	*objects2;
	void	*player;
	void	*player_w;
	void	*player_s;
	void	*player2;
	void	*player2_w;
	void	*player2_s;
	void	*floor;
	void	*win;
	void	*lose;
	void	*so_long;
	void	*enemy;
	void	*enemy2;
	void	*objects_t;
	void	*enemy_t;
	void	*player_t;
}	t_texture;

typedef struct s_map
{
	int			s_num;
	int			height;
	int			lenght;
	t_position	p_pos;
	t_position	e_pos;
	t_position	s_pos[10];
	int			score;
	int			current_score;
	char		**map;
	t_texture	img;
	void		*mlx_p;
	void		*win_p;
	int			steps;
	char		*s_steps;
}	t_map;

/*vld_errors*/

void		error(void);
void		error_rctngl(void);
void		prmtr_error(char **arr, int y);
void		symbols_error(char **arr, int y);
void		is_ber(char **argv);

/*validation commands*/
// 1
int			get_y(char **argv);
int			get_x(char **argv, int y);
void		rctngl_check(int y, int *str_lens);
void		is_rectangle(char **argv, int y);
t_map		*arg_validation(char **argv);
// 2
char		**get_arr(char **argv, int x, int y);
void		perimtr_check(char **arr, int x, int y);
void		e_p_check(int p_counter, int e_counter, char **map, int y);
void		symbols_check(char **map, int y);
// 3
int			sym_counter(char **map, int y, char sym);
t_position	get_pos(char **map, int y);
void		free_map(char **map, int y);
void		init_struct(t_map *map_d, int x, int y);
/*game commands*/
// 1
void		move_player_up(t_map *map_d);
void		move_player_down(t_map *map_d);
void		move_player_left(t_map *map_d);
void		move_player_right(t_map *map_d);

// 2
void		go_up(t_map *map_d);
void		go_down(t_map *map_d);
void		go_left(t_map *map_d);
void		go_right(t_map *map_d);
// 3
void		plus_step(t_map *map_d);
void		put_img_2_win(t_map *map_d, int x, int y);
int			map_rendering(t_map *map_d);
int			keys(int key, t_map *map_d);
// 4
void		ptr_free(void **ptr);
void		free_game(t_map *map_d);
// 5
void		sprot_up(t_map *map_d);
void		sprot_down(t_map *map_d);
void		sprot_left(t_map *map_d);
void		sprot_right(t_map *map_d);
// 6
void		init_img(t_map *map_d, int w, int h, int is);
void		sprot_a_i(t_map *map_d);
void		sprot_anim(t_map *map_d);
void		beer_anim(t_map *map_d);
int			anim(t_map *map_d);
// 7
int			lose(t_map *map_d);
int			win(t_map *map_d);
int			game_over_x(t_map *map_d);
int			game_over(t_map *map_d, int flag);

#endif
