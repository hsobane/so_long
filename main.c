/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:24:18 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/30 21:31:56 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mandatory/so_long.h"

void render_background(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 500)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.b, x, y);
			y += 50;
		}
		x += 50;
	}
}


int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 500, "Hello world!");
	vars.imgs.b = mlx_xpm_file_to_image(vars.mlx, "textures/brick.xpm", &vars.imgs.width, &vars.imgs.height);
	render_background(&vars);
	mlx_string_put(vars.mlx, vars.win, 0, 0, 0x00FFFFFF, "Hello world!");
	mlx_loop(vars.mlx);
	return (0);
}