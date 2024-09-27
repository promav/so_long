/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:15:53 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/27 15:27:02 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ending_game(mlx_t *mlx, t_p **vars, char **files)
{
	int	i;
	int	j;

	i = 0;
	while (i < 12)
	{
		mlx_delete_image(mlx, (*vars)->imgd[i]);
		mlx_delete_texture((*vars)->texture[i]);
		free(files[i]);
		i++;
	}
	j = 0;
	while (i < 4)
	{
		mlx_delete_image(mlx, (*vars)->imge[j]);
		mlx_delete_texture((*vars)->texture[i]);
		i++;
		j++;
	}
	free(files);
	free((*vars)->texture);
	free((*vars)->imgd);
	free((*vars)->imge);
}
