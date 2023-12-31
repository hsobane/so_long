/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:49:31 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/28 17:24:30 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*map_new(char *row, int width)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->row = row;
	map->width = width;
	map->height = 1;
	map->next = NULL;
	return (map);
}

void	map_addback(t_map **map, t_map *new)
{
	t_map	*tmp;

	if (!map)
		return ;
	if (!*map)
	{
		*map = new;
		return ;
	}
	tmp = *map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	map_clear(t_map **map)
{
	t_map	*tmp;

	if (!map)
		return ;
	while (*map)
	{
		tmp = (*map)->next;
		free((*map)->row);
		free(*map);
		*map = tmp;
	}
}

t_map	*map_last(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

int	map_size(t_map *map)
{
	int		size;
	t_map	*tmp;

	size = 0;
	tmp = map;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
