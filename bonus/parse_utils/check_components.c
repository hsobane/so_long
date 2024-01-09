/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:35:13 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/09 19:35:11 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_characters(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_components(t_map *map)
{
	int		p;
	int		e;
	int		c;
	int		m;
	t_map	*tmp;

	p = 0;
	e = 0;
	c = 0;
	m = 0;
	tmp = map;
	while (tmp)
	{
		p += num_of_occurence(tmp->row, 'P');
		e += num_of_occurence(tmp->row, 'E');
		c += num_of_occurence(tmp->row, 'C');
		m += num_of_occurence(tmp->row, 'M');
		if (check_characters(tmp->row, "01PECM"))
			return (write(2, "Map is invalid\n", 15), 1);
		tmp = tmp->next;
	}
	if (p != 1 || e != 1 || c == 0 || m == 0)
		return (write(2, "Map is invalid\n", 15), 1);
	return (0);
}
