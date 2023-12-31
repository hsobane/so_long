/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:58:05 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/30 19:43:17 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
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