/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:04:51 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/03 01:51:25 by hsobane          ###   ########.fr       */
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

static void	set_exit_pos(char **map, int *exit)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				exit[0] = j;
				exit[1] = i;
				return ;
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
	vars->imgs.b = mlx_xpm_file_to_image(vars->mlx, "textures/brick.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.w = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.c = mlx_xpm_file_to_image(vars->mlx, "textures/coin.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.e[0] = mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.e[1] = mlx_xpm_file_to_image(vars->mlx, "textures/exit_open.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.p[0] = mlx_xpm_file_to_image(vars->mlx, "textures/player_right.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.p[1] = mlx_xpm_file_to_image(vars->mlx, "textures/player_left.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.p[2] = mlx_xpm_file_to_image(vars->mlx, "textures/player_left.xpm",
			&vars->imgs.width, &vars->imgs.height);
	vars->imgs.p[3] = mlx_xpm_file_to_image(vars->mlx, "textures/player_right.xpm",
			&vars->imgs.width, &vars->imgs.height);
}

static void	init_data(t_vars *vars)
{
	vars->data.win_width =  50 * ft_strlen(vars->map[0]);
	vars->data.win_height = 50 * ft_matrix_len(vars->map);
	vars->data.collectibles = get_collectibles(vars->map);
	vars->data.direction = RIGHT;
	vars->data.steps = 0;
	set_exit_pos(vars->map, vars->data.exit);
}

void	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	init_data(vars);
	init_imgs(vars);
	vars->win = mlx_new_window(vars->mlx, vars->data.win_width,
			vars->data.win_height, "so_long");
}
