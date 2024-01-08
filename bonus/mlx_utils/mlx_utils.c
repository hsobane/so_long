/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsobane <hsobane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:25:59 by hsobane           #+#    #+#             */
/*   Updated: 2024/01/02 21:34:39 by hsobane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_steps(t_vars *vars)
{
	if (vars->data.steps == ((long int)1 << 31) - 1)
	{
		write(1, "Reached max number of steps\n", 28);
		exit_game(vars);
	}
	vars->data.steps += 1;
	write(1, "Steps: ", 7);
	ft_putnbr(vars->data.steps);
	write(1, "\n", 1);
}
