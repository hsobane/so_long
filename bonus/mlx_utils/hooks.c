/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:11:22 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/03 18:22:40 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int player_loop_hook(t_vars *vars)
{
	int		x;
	int		y;
	
	x = vars->imgs.p.x;
	y = vars->imgs.p.y;
	if (x == vars->data.exit[0] && y == vars->data.exit[1])
		mlx_put_image_to_window(vars->mlx, vars->win,
		vars->imgs.e.img[0][vars->imgs.e.j], x * 50, y * 50);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.w,
			x * 50, y * 50);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->imgs.p.img[vars->imgs.p.i][vars->imgs.p.j], x * 50, y * 50);
	vars->imgs.p.j++;
}

static int	enemy_loop_hook(t_vars *vars)
{
	int		x;
	int		y;
	
	x = vars->imgs.m.x;
	y = vars->imgs.m.y;
	if (x == vars->data.exit[0] && y == vars->data.exit[1])
		mlx_put_image_to_window(vars->mlx, vars->win,
		vars->imgs.m.img[vars->imgs.m.j][vars->imgs.m.j], x * 50, y * 50);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.w,
			x * 50, y * 50);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->imgs.m.img[vars->imgs.m.i][vars->imgs.m.j], x * 50, y * 50);
	vars->imgs.m.j++;
}

static int open_exit_loop(t_vars *vars)
{
	int			x;
	int			y;
	static int	i;
	
	if (i != 0 || vars->data.collectibles != 0)
		return (0);
	x = vars->imgs.p.x;
	y = vars->imgs.p.y;
	if (x == vars->data.exit[0] && y == vars->data.exit[1])
		return (vars->imgs.e.j++, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.w,
		x * 50, y * 50);
	vars->imgs.e.j++;
}

int	display_background(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->data.win_width / 50)
	{
		y = 0;
		while (y < vars->data.win_height / 50)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.b,
				x * 50, y * 50);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.w,
					x * 50, y * 50);
			else if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.c,
					x * 50, y * 50);
			y++;
		}
		x++;
	}
}

int	loop_hook_all(t_vars *vars)
{
	usleep(100000);
	mlx_clear_window(vars->mlx, vars->win);
	display_background(vars);
	player_loop_hook(vars);
	enemy_loop_hook(vars);
	open_exit_loop(vars);
	return (0);
}
