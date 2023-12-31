/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:25:33 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/30 20:22:35 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_pos(t_map *map, int *x, int *y)
{
	int		i;
	t_map	*tmp;

	tmp = map;
	*y = 0;
	*x = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->row[i])
		{
			if (tmp->row[i] == 'P')
			{
				*x = i;
				return ;
			}
			i++;
		}
		*y += 1;
		tmp = tmp->next;
	}
}

static int	get_collectibles(t_map *map)
{
	int		c;
	t_map	*tmp;

	c = 0;
	tmp = map;
	while (tmp)
	{
		c += num_of_occurence(tmp->row, 'C');
		tmp = tmp->next;
	}
	return (c);
}

int	check_path(t_map *map)
{
	int		c;
	int		x;
	int		y;
	char	**matrix;

	matrix = map_to_matrix(map);
	if (!matrix)
		return (1);
	c = get_collectibles(map);
	get_player_pos(map, &x, &y);
	if (!flood_fill(matrix, x, y, c))
		return (free(matrix), write(2, "Map is invalid\n", 15), 1);
	free(matrix);
	return (0);
}
