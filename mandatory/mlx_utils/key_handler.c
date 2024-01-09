/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:58:05 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/08 13:50:24 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_imgs(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->imgs.b);
	mlx_destroy_image(vars->mlx, vars->imgs.w);
	mlx_destroy_image(vars->mlx, vars->imgs.c);
	mlx_destroy_image(vars->mlx, vars->imgs.e[0]);
	mlx_destroy_image(vars->mlx, vars->imgs.e[1]);
	while (i < 4)
		mlx_destroy_image(vars->mlx, vars->imgs.p[i++]);
}

int	exit_game(t_vars *vars)
{
	map_clear(&vars->map_raw);
	free(vars->map);
	free_imgs(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	//mlx_destroy_display(vars->mlx);
	//free(vars->mlx);
	printf("exit game\n");
	fflush(stdout);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		exit_game(vars);
	else if (keycode == LEFT || keycode == RIGHT || keycode == UP
		|| keycode == DOWN)
	{
		vars->data.direction = keycode;
		move_lplayer(vars, keycode);
	}
	return (0);
}