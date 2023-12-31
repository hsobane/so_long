/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:23:38 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/29 16:00:04 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_to_matrix(t_map *map)
{
	char	**matrix;
	int		i;
	t_map	*tmp;

	matrix = malloc(sizeof(char *) * (map_size(map) + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	tmp = map;
	while (tmp)
	{
		matrix[i] = tmp->row;
		i++;
		tmp = tmp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

void   free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix[i]);
	free(matrix);
}
