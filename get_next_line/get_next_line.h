/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:32:16 by ubunto            #+#    #+#             */
/*   Updated: 2023/12/13 19:22:57 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	str_lcpy(char *dst, char const *src, size_t n);
size_t	line_size(char *buff, int *is_lined);

#endif