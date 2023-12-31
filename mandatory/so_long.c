/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:20:49 by hsobane           #+#    #+#             */
/*   Updated: 2023/12/30 20:19:11 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	printf("\n");
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	printf("\n");
}

void	reset_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'V')
				map[i][j] = '0';
			else if (map[i][j] == 'U')
				map[i][j] = 'C';
			else if (map[i][j] == 'Q')
				map[i][j] = 'P';
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	*map;

	map = parse_args(argc, argv);
	vars.map = map_to_matrix(map);
	vars.map_raw = map;
	if (!vars.map)
	{
		map_clear(&map);
		exit(1);
	}
	reset_map(vars.map);
	init_mlx(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_loop_hook(vars.mlx, move_gplayer, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
