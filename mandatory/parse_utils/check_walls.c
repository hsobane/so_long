/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:13 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/28 16:36:39 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_map *map)
{
	int		i;
	t_map	*tmp;
	t_map	*tmp2;

	if (!map)
		return (1);
	tmp = map;
	tmp2 = map;
	while (tmp->next)
	{
		if (tmp->row[0] != '1' || tmp->row[tmp->width - 1] != '1')
			return (write(2, "Map is not closed\n", 18), 1);
		tmp = tmp->next;
	}
	i = 0;
	while (tmp->row[i])
	{
		if (tmp->row[i] != '1' || tmp2->row[i] != '1')
			return (write(2, "Map is not closed\n", 18), 1);
		i++;
	}
	return (0);
}
