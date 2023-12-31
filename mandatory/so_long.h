/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:14:52 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/30 18:04:47 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <mlx.h>

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ESC 53

typedef struct s_map
{
	char			*row;
	int				width;
	int				height;
	struct s_map	*next;
}				t_map;

typedef struct s_imgs
{
	void	*p[4];
	void	*m;
	void	*w;
	void	*e[2];
	void	*c;
	void	*b;
	int		width;
	int		height;
}				t_imgs;

typedef struct s_data
{
	int	direction;
	int	collectibles;
	int	steps;
	int	exit[2];
	int	win_width;
	int	win_height;
}			t_data;

typedef struct s_vars
{
	t_imgs	imgs;
	t_data	data;
	t_map	*map_raw;
	char	**map;
	void	*mlx;
	void	*win;
}			t_vars;


// main
void	print_matrix(char **matrix);

// parse_args
int		check_dimension(t_map *map);
int		check_walls(t_map *map);
int		check_components(t_map *map);
int		flood_fill(char **map, int x, int y, int c);
int		check_path(t_map *map);
t_map	*parse_args(int argc, char **argv);
void	get_player_pos(t_map *map, int *x, int *y);

// map_utils
void	map_addback(t_map **map, t_map *new);
t_map	*map_new(char *row, int width);
t_map	*map_last(t_map *map);
void	map_clear(t_map **map);
char	**map_to_matrix(t_map *map);
int		map_size(t_map *map);

// string_utils
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
int		num_of_occurence(char *str, char c);

// mlx_utils
void	move_lplayer(t_vars *vars, int direction);
int		move_gplayer(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
void	exit_game(t_vars *vars);
void	init_mlx(t_vars *vars);

#endif