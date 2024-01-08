/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:20:49 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/03 00:09:04 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# define BLUE "\033[0;34m"
# define RESET "\033[0m"

void	print_matrix(char **matrix, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	printf("\n");
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (i == y && j == x)
				printf(BLUE "%c" RESET, matrix[i][j]);
			else
				printf("%c", matrix[i][j]);
			j++;
		}
		printf("\n");
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
			else if (map[i][j] == 'K')
				map[i][j] = 'E';
			else if (map[i][j] == 'e')
				map[i][j] = 'E';
			else if (map[i][j] == 'c')
				map[i][j] = 'C';
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
	mlx_hook(vars.win, 17, 1L << 17, exit_game, &vars);
	write(1, "Steps: ", 7);
	ft_putnbr(vars.data.steps);
	write(1, "\n", 1);
	mlx_loop_hook(vars.mlx, move_gplayer, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
