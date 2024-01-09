/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:04:51 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/09 16:08:00 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_matrix_len(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

static void	set_position(char **map, int *coord, char c)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				coord[0] = j;
				coord[1] = i;
			}
			j++;
		}
		i++;
	}
}

static int	get_collectibles(char **map)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

static void	init_imgs(t_vars *vars)
{
	vars->imgs.b = mlx_xpm_file_to_image(vars->mlx, "textures/wall_11111.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.w = mlx_xpm_file_to_image(vars->mlx, "textures/brick_11.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.c = mlx_xpm_file_to_image(vars->mlx, "textures/coin_1.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.e[0] = mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.e[1] = mlx_xpm_file_to_image(vars->mlx, "textures/exit_open.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.p[0] = mlx_xpm_file_to_image(vars->mlx, "textures/player_right.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.p[1] = mlx_xpm_file_to_image(vars->mlx, "textures/player_left.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.m[0] = mlx_xpm_file_to_image(vars->mlx, "textures/enemy_l.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.m[1] = mlx_xpm_file_to_image(vars->mlx, "textures/enemy_r.xpm",
			&vars->imgs.width, &vars->imgs.height);
}

static void	init_data(t_vars *vars)
{
	vars->data.win_width =  50 * ft_strlen(vars->map[0]);
	vars->data.win_height = 50 * ft_matrix_len(vars->map);
	vars->data.collectibles = get_collectibles(vars->map);
	vars->data.enemy_on_col = 0;
	vars->data.eldirection = LEFT;
	vars->data.edirection = LEFT;
	vars->data.pdirection = RIGHT;
	vars->data.pldirection = RIGHT;
	vars->data.steps = 0;
	set_position(vars->map, vars->data.exit, 'E');
	set_position(vars->map, vars->data.enemy, 'M');
	set_position(vars->map, vars->data.player, 'P');
}

void	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	init_data(vars);
	init_imgs(vars);
	vars->win = mlx_new_window(vars->mlx, vars->data.win_width,
			vars->data.win_height, "so_long");
}
