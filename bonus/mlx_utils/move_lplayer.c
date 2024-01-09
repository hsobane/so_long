/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lplayer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:39:19 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/09 12:11:29 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void go_left(t_vars *vars, int x, int y)
{
	if (vars->map[y][x - 1] == 'C')
		vars->data.collectibles -= 1;
	else if (vars->map[y][x - 1] == '1')
		return ;
	if (vars->data.exit[0] == x && vars->data.exit[1] == y)
		vars->map[y][x] = 'E';
	else
		vars->map[y][x] = '0';
	vars->map[y][x - 1] = 'P';
	vars->data.pldirection = LEFT;
	vars->data.pdirection = LEFT;
	vars->data.player[0] = x - 1;
	vars->data.player[1] = y;
	vars->data.steps += 1;
}

static void go_right(t_vars *vars, int x, int y)
{
	if (vars->map[y][x + 1] == 'C')
		vars->data.collectibles -= 1;
	else if (vars->map[y][x + 1] == '1')
		return ;
	if (vars->data.exit[0] == x && vars->data.exit[1] == y)
		vars->map[y][x] = 'E';
	else
		vars->map[y][x] = '0';
	vars->map[y][x + 1] = 'P';
	vars->data.pldirection = RIGHT;
	vars->data.pdirection = RIGHT;
	vars->data.player[0] = x + 1;
	vars->data.player[1] = y;
	vars->data.steps += 1;
}

static void go_up(t_vars *vars, int x, int y)
{
	if (vars->map[y - 1][x] == 'C')
		vars->data.collectibles -= 1;
	else if (vars->map[y - 1][x] == '1')
		return ;
	if (vars->data.exit[0] == x && vars->data.exit[1] == y)
		vars->map[y][x] = 'E';
	else
		vars->map[y][x] = '0';
	vars->map[y - 1][x] = 'P';
	vars->data.pdirection = UP;
	vars->data.player[0] = x;
	vars->data.player[1] = y - 1;
	vars->data.steps += 1;
}

static void go_down(t_vars *vars, int x, int y)
{
	if (vars->map[y + 1][x] == 'C')
		vars->data.collectibles -= 1;
	else if (vars->map[y + 1][x] == '1')
		return ;
	if (vars->data.exit[0] == x && vars->data.exit[1] == y)
		vars->map[y][x] = 'E';
	else
		vars->map[y][x] = '0';
	vars->map[y + 1][x] = 'P';
	vars->data.pdirection = DOWN;
	vars->data.player[0] = x;
	vars->data.player[1] = y + 1;
	vars->data.steps += 1;
}

void	move_lplayer(t_vars *vars, int direction)
{
	int	x;
	int	y;

	get_player_pos(vars->map_raw, &x, &y);
	if (direction == LEFT)
		go_left(vars, x, y);
	else if (direction == RIGHT)
		go_right(vars, x, y);
	else if (direction == UP)
		go_up(vars, x, y);
	else if (direction == DOWN)
		go_down(vars, x, y);
	else if (direction == ESC)
		exit_game(vars);
}
