/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:25:12 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 17:33:37 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ground(t_p **vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*vars)->w)
	{
		j = 0;
		while (j < (*vars)->h)
		{
			if (mlx_image_to_window((*vars)->mlx, \
			(*vars)->imge[0], 128 * i, 128 * j) == -1)
				error();
			j++;
		}
		i++;
	}
}

void	ft_wall(t_p **vars)
{
	int	x;
	int	y;

	y = 0;
	while ((*vars)->map[y])
	{
		x = 0;
		while ((*vars)->map[y][x] != '\0')
		{
			if ((*vars)->map[y][x] == '1')
			{
				if (mlx_image_to_window((*vars)->mlx, \
				(*vars)->imge[4], 128 * x, 128 * y) == -1)
					error();
			}
			x++;
		}
		y++;
	}
}

void	ft_charactec(t_p **vars, t_map map_coor)
{
	int	i;

	if (mlx_image_to_window((*vars)->mlx, (*vars)->imgd[0], \
	map_coor.p_x * 128, map_coor.p_y * 128) == -1)
		error();
	i = 0;
	while (i < 12)
	{
		if (mlx_image_to_window((*vars)->mlx, \
		(*vars)->imgd[i], -10000, -10000) == -1)
			error();
		i++;
	}
	(*vars)->x = map_coor.p_x * 128;
	(*vars)->y = map_coor.p_y * 128;
}

void	ft_images_to_window(t_p **vars, t_map map_coor)
{
	int	i;

	(*vars)->w = map_coor.columns;
	(*vars)->h = map_coor.rows;
	ft_ground(vars);
	ft_wall(vars);
	(*vars)->n_colec = map_coor.n_colec;
	(*vars)->left_colec = map_coor.n_colec;
	ft_charactec(vars, map_coor);
	i = 0;
	while (i < map_coor.n_colec)
	{
		if (mlx_image_to_window((*vars)->mlx, (*vars)->imge[1], \
		map_coor.c_x[i] * 128, map_coor.c_y[i] * 128) == -1)
			error();
		i++;
	}
	free(map_coor.c_x);
	free(map_coor.c_y);
	if (mlx_image_to_window((*vars)->mlx, (*vars)->imge[2], \
	map_coor.e_x * 128, map_coor.e_y * 128) == -1)
		error();
	if (mlx_image_to_window((*vars)->mlx, (*vars)->imge[3], -500, -500) == -1)
		error();
}
