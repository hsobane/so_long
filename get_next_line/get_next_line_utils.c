/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:32:06 by ubunto            #+#    #+#             */
/*   Updated: 2023/12/27 20:18:35 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_lcpy(char *dst, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}

size_t	line_size(char *buff, int *is_lined)
{
	size_t	sline;

	sline = 0;
	while (buff[sline] && buff[sline] != '\n')
		sline++;
	*is_lined = 0;
	*is_lined += (buff[sline] == '\n');
	sline += *is_lined;
	return (sline);
}
