/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:24:07 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/09 19:32:17 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_file_extention(char *file_name)
{
	int	i;
	int	j;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] != 'r' || file_name[i - 2] != 'e'
		|| file_name[i - 3] != 'b' || file_name[i - 4] != '.')
	{
		write(2, "Wrong file extension\n", 21);
		exit(1);
	}
	j = 0;
	while (file_name[j] && file_name[j] != '/')
		j++;
	if (file_name[j] == '/' && i - j - 1 < 5)
	{
		write(2, "Wrong file name\n", 16);
		exit(1);
	}
}

static int	open_wrapper(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Can't open file\n", 16);
		exit(1);
	}
	return (fd);
}

static t_map	*get_raw_map(int fd)
{
	char	*line;
	t_map	*map;
	t_map	*tmp;

	map = NULL;
	line = get_next_line(fd);
	while (line != NULL && line != (void *)-1)
	{
		tmp = map_new(line, ft_strlen(line));
		if (!tmp)
		{
			map_clear(&map);
			exit(1);
		}
		map_addback(&map, tmp);
		line = get_next_line(fd);
	}
	if (line == (void *)-1)
	{
		map_clear(&map);
		exit(1);
	}
	(tmp->width)++;
	return (map);
}

t_map	*parse_args(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map_path>\n", 28);
		exit(1);
	}
	check_file_extention(argv[1]);
	printf("check\n");
	fd = open_wrapper(argv[1]);
	printf("check\n");
	map = get_raw_map(fd);
	printf("check\n");
	if (check_dimension(map) || check_walls(map) || check_components(map)
		|| check_path(map))
	{
		map_clear(&map);
		exit(1);
	}
	printf("check\n");
	if (close(fd) < 0)
	{
		write(2, "Can't close file\n", 17);
		map_clear(&map);
		exit(1);
	}
	printf("check\n");
	return (map);
}
