/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:31:42 by ubunto            #+#    #+#             */
/*   Updated: 2023/12/30 14:06:27 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	shift_buff(char *buff, size_t length)
{
	size_t	i;

	i = 0;
	while (buff[length + i])
	{
		buff[i] = buff[length + i];
		i++;
	}
	while (buff[i])
		buff[i++] = 0;
}

static int	read_wr(char *buff, int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
		shift_buff(buff, BUFFER_SIZE);
	return (bytes_read);
}

static int	get_line(char *buff, char **line)
{
	size_t	l;
	size_t	sline;
	char	*new_line;
	int		is_lined;

	l = 0;
	while (*line && (*line)[l])
		l++;
	sline = line_size(buff, &is_lined);
	if (sline == 0)
		return (0);
	new_line = (char *)malloc(sizeof(char) * (l + sline + 1));
	if (!new_line)
		return (-1);
	str_lcpy(new_line, *line, l);
	str_lcpy(new_line + l, buff, sline);
	shift_buff(buff, sline);
	if (*line)
		free(*line);
	*line = new_line;
	return (is_lined);
}

static int	get_rest_line(int fd, char *buff, char **line)
{
	int		mok;
	ssize_t	bread;

	mok = get_line(buff, line);
	if (mok < 0)
		return (-1);
	if (mok == 1)
		return (1);
	bread = read_wr(buff, fd);
	if (bread < 0)
		return (-1);
	else if (bread == 0)
		return (1);
	if (get_rest_line(fd, buff, line) < 0)
		return (-1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + (size_t)1];
	char		*line;
	int			i;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buff[i++] = 0;
		return ((void *)-1);
	}
	line = 0;
	buff[BUFFER_SIZE] = 0;
	if (get_rest_line(fd, buff, &line) > 0)
		return (line);
	if (line)
		free(line);
	return ((void *)-1);
}
