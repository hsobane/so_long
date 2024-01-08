/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:24:18 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/03 17:56:10 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ESC 65307

typedef struct s_imgs
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
}				t_imgs;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_imgs	b;
	t_imgs	w;
}				t_vars;

// void render_background(t_vars *vars)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < 1000)
// 	{
// 		y = 0;
// 		while (y < 500)
// 		{
// 			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.b, x, y);
// 			y += 50;
// 		}
// 		x += 50;
// 	}
// }

int	render_b(t_vars *vars)
{
	usleep(1000000);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->b.img, vars->b.x, vars->b.y);
	vars->b.x += 50;
	return (0);
}

int render_w(t_vars *vars)
{
	usleep(5000000);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->w.img, vars->w.x, vars->w.y);
	vars->w.x += 50;
	return (0);
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_win(vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 500, "Hello world!");
	vars.b.img = mlx_xpm_file_to_image(vars.mlx, "textures/brick.xpm", &vars.b.width, &vars.b.height);
	vars.w.img = mlx_xpm_file_to_image(vars.mlx, "textures/wall.xpm", &vars.w.width, &vars.w.height);
	vars.b.x = 0;
	vars.b.y = 0;
	vars.w.y = 50;
	vars.w.x = 0;
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_string_put(vars.mlx, vars.win, 0, 0, 0x00FFFFFF, "Hello world!");
	mlx_loop_hook(vars.mlx, render_w, &vars);
	mlx_loop_hook(vars.mlx, render_b, &vars);
	mlx_loop(vars.mlx);
	return (0);
}