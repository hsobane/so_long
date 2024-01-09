/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gplayer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:55:41 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/09 20:18:04 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_steps(int steps, char *str, int *i)
{
	if (steps > 9)
		get_steps(steps / 10, str, i);
	str[*i] = steps % 10 + '0';
	str[*i + 1] = '\0';
	*i += 1;
}

static void display_enemy(t_vars *vars, int x, int y)
{
	if (x == vars->data.exit[0] && y == vars->data.exit[1])
	{
		if (vars->data.collectibles == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.e[1], x * 50, y * 50);
		else if (vars->data.collectibles != 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.e[0], x * 50, y * 50);
	}
	if (vars->data.edirection == LEFT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.m[0], x * 50, y * 50);
	else if (vars->data.edirection == RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.m[1], x * 50, y * 50);
	else if (vars->data.eldirection == LEFT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.m[0], x * 50, y * 50);
	else if (vars->data.eldirection == RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.m[1], x * 50, y * 50);
}

static void display_player(t_vars *vars, int x, int y, int direction)
{
	if (x == vars->data.exit[0] && y == vars->data.exit[1])
	{
		if (vars->data.collectibles == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.e[1], x * 50, y * 50);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.e[0], x * 50, y * 50);
	}
	if (direction == LEFT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.p[0], x * 50, y * 50);
	else if (direction == RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.p[1], x * 50, y * 50);
	else if (direction == UP)
		display_player(vars, x, y, vars->data.pldirection);
	else if (direction == DOWN)
		display_player(vars, x, y, vars->data.pldirection);
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
	else if (vars->map[y][x] == 'M')
		display_enemy(vars, x, y);
}

int	move_gplayer(t_vars *vars)
{
	int		x;
	int		y;
	char	steps[11];
	int		i;

	x = 0;
	move_lenemy(vars);
	while (x < vars->data.win_width / 50)
	{
		y = 0;
		while (y < vars->data.win_height / 50)
		{
			display_img(vars, x, y, vars->data.pdirection);
			y++;
		}
		x++;
	}
	i = 0;
	get_steps(vars->data.steps, steps, &i);
	mlx_string_put(vars->mlx, vars->win, 10, 20, 0x00FFFFFF, steps);
	mlx_do_sync(vars->mlx);
	usleep(100000);
	if (vars->data.player[0] == vars->data.enemy[0] && vars->data.player[1] == vars->data.enemy[1])
	{
		printf("You lost!\n");
		exit_game(vars);
	}
	if (vars->data.player[0] == vars->data.exit[0] && vars->data.player[1] == vars->data.exit[1] && vars->data.collectibles == 0)
	{
		printf("You won!\n");
		exit_game(vars);
	}
	return (0);
}
