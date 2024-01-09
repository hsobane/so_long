/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dimension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:37:59 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/09 20:13:45 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	delete_newline(t_map *map)
{
	t_map	*tmp;
	int		i;

	tmp = map;
	while (tmp)
	{
		i = 0;
		while (tmp->row[i])
		{
			if (tmp->row[i] == '\n')
			{
				tmp->row[i] = '\0';
				tmp->width = tmp->width - 1;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	check_dimension(t_map *map)
{
	int		width;
	t_map	*tmp;
	int		height;

	height = 0;
	if (!map)
		return (write(2, "Map is empty\n", 13), 1);
	width = map->width;
	tmp = map;
	while (tmp)
	{
		height++;
		if (tmp->width != width)
			return (write(2, "Map is not rectangular\n", 23), 1);
		tmp = tmp->next;
	}
	if (height < 3 || width < 3)
		return (write(2, "Map is too small\n", 17), 1);
	if (height > 100 || width > 102)
		return (write(2, "Map is too big\n", 15), 1);
	delete_newline(map);
	return (0);
}
