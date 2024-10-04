/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:54:22 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 19:18:49 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectable_control(t_p **vars)
{
	int	i;

	i = -1;
	while (++i < (*vars)->n_colec)
	{
		if (((*vars)->imgd[(*vars)->p]->instances[0].x == \
		(*vars)->imge[1]->instances[i].x) && \
		((*vars)->imgd[(*vars)->p]->instances[0].y == \
		(*vars)->imge[1]->instances[i].y))
		{
			(*vars)->imge[1]->instances[i].x = -1000;
			(*vars)->left_colec--;
			if ((*vars)->left_colec == 0)
				(*vars)->open_door = 1;
		}
	}
	if ((*vars)->open_door == 1)
	{
		(*vars)->e_x = (*vars)->imge[2]->instances[0].x;
		(*vars)->e_y = (*vars)->imge[2]->instances[0].y;
		(*vars)->imge[3]->instances[0].x = (*vars)->e_x;
		(*vars)->imge[3]->instances[0].y = (*vars)->e_y;
		(*vars)->imge[2]->instances[0].x = -1000;
		(*vars)->open_door = 0;
	}
}

void	rest_position(t_p **vars)
{
	if ((*vars)->p == 11 || (*vars)->p == 10)
	{
		change_image(vars, 9);
	}
	if ((*vars)->p == 2 || (*vars)->p == 1)
	{
		change_image(vars, 0);
	}
	if ((*vars)->p == 5 || (*vars)->p == 4)
	{
		change_image(vars, 3);
	}
	if ((*vars)->p == 8 || (*vars)->p == 7)
	{
		change_image(vars, 6);
	}
}

void	ft_hook(void *param)
{
	t_p	*vars;

	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		ending_game(vars->mlx, vars);
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_UP) \
	&& vars->map[vars->imgd[vars->p]->instances[0].y / 128 - 1] \
	[vars->imgd[vars->p]->instances[0].x / 128] != '1')
		move_up(&vars);
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_DOWN) \
	&& vars->map[vars->imgd[vars->p]->instances[0].y / 128 + 1] \
	[vars->imgd[vars->p]->instances[0].x / 128] != '1')
		move_down(&vars);
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT) \
	&& vars->map[vars->imgd[vars->p]->instances[0].y / 128] \
	[vars->imgd[vars->p]->instances[0].x / 128 - 1] != '1')
		move_left(&vars);
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT) \
	&& vars->map[vars->imgd[vars->p]->instances[0].y / 128] \
	[vars->imgd[vars->p]->instances[0].x / 128 + 1] != '1')
		move_right(&vars);
	else
		rest_position(&vars);
}
