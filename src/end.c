/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:15:53 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 19:22:26 by pabromer         ###   ########.fr       */
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
