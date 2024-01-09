/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lenemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:29:41 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/09 17:26:16 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_lenemy_left(t_vars *vars)
{
	int	on_col;

	on_col = vars->data.enemy_on_col;
	if (vars->map[vars->data.enemy[1]][vars->data.enemy[0] - 1] == 'C')
		vars->data.enemy_on_col = 1;
	else
		vars->data.enemy_on_col = 0;
	if (vars->map[vars->data.enemy[1]][vars->data.enemy[0] - 1] == '1')
		return ;
	if (vars->data.exit[0] == vars->data.enemy[0] && vars->data.exit[1] == vars->data.enemy[1])
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = 'E';
	else if (on_col == 1)
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = 'C';
	else
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = '0';
	vars->map[vars->data.enemy[1]][vars->data.enemy[0] - 1] = 'M';
	vars->data.edirection = LEFT;
	vars->data.eldirection = LEFT;
	vars->data.enemy[0] -= 1;
}

static void	move_lenemy_right(t_vars *vars)
{
	int	on_col;

	on_col = vars->data.enemy_on_col;
	if (vars->map[vars->data.enemy[1]][vars->data.enemy[0] + 1] == 'C')
		vars->data.enemy_on_col = 1;
	else
		vars->data.enemy_on_col = 0;
	if (vars->map[vars->data.enemy[1]][vars->data.enemy[0] + 1] == '1')
		return ;
	if (vars->data.exit[0] == vars->data.enemy[0] && vars->data.exit[1] == vars->data.enemy[1])
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = 'E';
	else if (on_col == 1)
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = 'C';
	else
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = '0';
	vars->map[vars->data.enemy[1]][vars->data.enemy[0] + 1] = 'M';
	vars->data.edirection = RIGHT;
	vars->data.eldirection = RIGHT;
	vars->data.enemy[0] += 1;
}

static void	move_lenemy_up(t_vars *vars)
{
	int	on_col;

	on_col = vars->data.enemy_on_col;
	if (vars->map[vars->data.enemy[1] - 1][vars->data.enemy[0]] == 'C')
		vars->data.enemy_on_col = 1;
	else
		vars->data.enemy_on_col = 0;
	if (vars->map[vars->data.enemy[1] - 1][vars->data.enemy[0]] == '1')
		return ;
	if (vars->data.exit[0] == vars->data.enemy[0] && vars->data.exit[1] == vars->data.enemy[1])
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = 'E';
	else if (on_col == 1)
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = 'C';
	else
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = '0';
	vars->map[vars->data.enemy[1] - 1][vars->data.enemy[0]] = 'M';
	vars->data.edirection = UP;
	vars->data.enemy[1] -= 1;
}

static void	move_lenemy_down(t_vars *vars)
{
	int	on_col;

	on_col = vars->data.enemy_on_col;
	if (vars->map[vars->data.enemy[1] + 1][vars->data.enemy[0]] == 'C')
		vars->data.enemy_on_col = 1;
	else
		vars->data.enemy_on_col = 0;
	if (vars->map[vars->data.enemy[1] + 1][vars->data.enemy[0]] == '1')
		return ;
	if (vars->data.exit[0] == vars->data.enemy[0] && vars->data.exit[1] == vars->data.enemy[1])
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = 'E';
	else if (on_col == 1)
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = 'C';
	else
		vars->map[vars->data.enemy[1]][vars->data.enemy[0]] = '0';
	vars->map[vars->data.enemy[1] + 1][vars->data.enemy[0]] = 'M';
	vars->data.edirection = DOWN;
	vars->data.enemy[1] += 1;
}

void	next_position(t_vars *vars, int *next)
{
	int	x;
	int	y;
	
	x = vars->data.enemy[0];
	y = vars->data.enemy[1];
	if (vars->map[y][x - 1] != '1' && x > vars->data.player[0])
		next[0] = x - 1;
	else if (vars->map[y][x + 1] != '1' && x < vars->data.player[0])
		next[0] = x + 1;
	else if (vars->map[y - 1][x] != '1' && y > vars->data.player[1])
		next[1] = y - 1;
	else if (vars->map[y + 1][x] != '1' && y < vars->data.player[1])
		next[1] = y + 1;
}

void	move_lenemy(t_vars *vars)
{
	int			next[2];
	static int	i;

	i++;
	next[0] = vars->data.enemy[0];
	next[1] = vars->data.enemy[1];
	next_position(vars, next);
	if (i % 5 != 0)
		return ;
	if (next[0] == vars->data.enemy[0] - 1)
		move_lenemy_left(vars);
	else if (next[0] == vars->data.enemy[0] + 1)
		move_lenemy_right(vars);
	else if (next[1] == vars->data.enemy[1] - 1)
		move_lenemy_up(vars);
	else if (next[1] == vars->data.enemy[1] + 1)
		move_lenemy_down(vars);
}
