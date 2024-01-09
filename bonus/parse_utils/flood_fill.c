/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:29:57 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/09 20:03:31 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	empty_square(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'U'
		|| map[y][x] == 'Q' || map[y][x] == 'K' || map[y][x] == 'N')
		return (0);
	return (1);
}

static void	set_square(char **map, int x, int y, int *c)
{
	if (map[y][x] == '0')
		map[y][x] = 'V';
	else if (map[y][x] == 'P')
		map[y][x] = 'Q';
	else if (map[y][x] == 'E')
	{
		*c -= 1;
		map[y][x] = 'K';
	}
	else if (map[y][x] == 'e')
		map[y][x] = 'K';
	else if (map[y][x] == 'C')
	{
		*c -= 1;
		map[y][x] = 'U';
	}
	else if (map[y][x] == 'c')
		map[y][x] = 'U';
	else if (map[y][x] == 'M')
		map[y][x] = 'N';
}

void	unset_square(char **map, int x, int y)
{
	if (map[y][x] == 'Q')
		map[y][x] = 'P';
	else if (map[y][x] == 'K')
		map[y][x] = 'e';
	else if (map[y][x] == 'U')
		map[y][x] = 'c';
	else if (map[y][x] == 'N')
		map[y][x] = 'M';
}

int	flood_fill(char **map, int x, int y, int *c)
{
	if (*c == -1)
		return (1);
	if (empty_square(map, x, y) == 0)
		return (0);
	set_square(map, x, y, c);
	if (flood_fill(map, x + 1, y, c))
		return (1);
	if (flood_fill(map, x - 1, y, c))
		return (1);
	if (flood_fill(map, x, y + 1, c))
		return (1);
	if (flood_fill(map, x, y - 1, c))
		return (1);
	return (0);
}
