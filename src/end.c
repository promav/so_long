/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:15:53 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/07 09:24:26 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ending_game(mlx_t *mlx, t_p *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < 12)
	{
		mlx_delete_image(mlx, vars->imgd[i]);
		mlx_delete_texture(vars->texture[i]);
		i++;
	}
	j = 0;
	while (j < 5)
	{
		mlx_delete_image(mlx, vars->imge[j]);
		mlx_delete_texture(vars->texture[i]);
		i++;
		j++;
	}
	free(vars->texture);
	free(vars->imgd);
	free(vars->imge);
	ft_free_map(vars->map);
	mlx_close_window(mlx);
	mlx_terminate(mlx);
	exit (EXIT_SUCCESS);
}

void	ft_crossing_door(t_p *vars)
{
	if (vars->imgd[vars->p]->instances[0].x == \
	vars->imge[3]->instances[0].x \
	&& (vars->imgd[vars->p]->instances[0].y == \
	vars->imge[3]->instances[0].y))
	{
		ft_printf("Congrats! You finish the game successfully!");
		ending_game(vars->mlx, vars);
	}
}
