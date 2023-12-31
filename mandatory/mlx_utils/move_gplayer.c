/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gplayer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:55:41 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/30 21:13:36 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void display_player(t_vars *vars, int x, int y, int direction)
{
	if (x == vars->data.exit[0] && y == vars->data.exit[1])
	{
		if (vars->data.collectibles == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.e[1], x * 50, y * 50);
		else if (vars->data.collectibles != 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.e[0], x * 50, y * 50);
	}
	if (direction == LEFT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.p[0], x * 50, y * 50);
	else if (direction == RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.p[1], x * 50, y * 50);
	else if (direction == UP)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.p[2], x * 50, y * 50);
	else if (direction == DOWN)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.p[3], x * 50, y * 50);
}

static void	display_img(t_vars *vars, int x, int y, int direction)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.b, x * 50, y * 50);
	if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.w, x * 50, y * 50);
	else if (vars->map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.c, x * 50, y * 50);
	else if (vars->map[y][x] == 'E' && vars->data.collectibles == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.e[1], x * 50, y * 50);
	else if (vars->map[y][x] == 'E' && vars->data.collectibles != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.e[0], x * 50, y * 50);
	else if (vars->map[y][x] == 'P')
		display_player(vars, x, y, direction);
	else if (vars->map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.b, x * 50, y * 50);
}

int	move_gplayer(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->data.win_width / 50)
	{
		y = 0;
		while (y < vars->data.win_height / 50)
		{
			display_img(vars, x, y, vars->data.direction);
			y++;
		}
		x++;
	}
	return (0);
}
