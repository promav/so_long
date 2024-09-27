/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:24:08 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/27 15:30:56 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_p	*init_vars(mlx_t *mlx)
{
	t_p	*vars;

	vars = (t_p *)malloc(sizeof(t_p));
	vars->mlx = mlx;
	vars->texture = NULL;
	vars->imgd = NULL;
	vars->imge = NULL;
	vars->p = 0;
	vars->open_door = 0;
	vars->x = 0;
	vars->y = 0;
	vars->step = 0;
	vars->speed = 0;
	vars->next = NULL;
	return (vars);
}

char	**file_names(void)
{
	int		i;
	char	*num;
	char	**names;

	i = 0;
	names = (char **)malloc(12 * sizeof(char *));
	while (i < 12)
	{
		num = ft_itoa(i);
		names[i] = ft_strjoin("./Gohan/Gohan", num);
		names[i] = ft_strjoin(names[i], ".png");
		i++;
	}
	return (names);
}

mlx_texture_t	**ft_load_textures(char **names)
{
	mlx_texture_t	**texture;
	int				i;

	i = 0;
	texture = malloc(16 * sizeof(mlx_texture_t *));
	while (i < 12)
	{
		texture[i] = mlx_load_png(names[i]);
		i++;
	}
	texture[12] = mlx_load_png("./Gohan/Ground.png");
	texture[13] = mlx_load_png("./Gohan/BD.png");
	texture[14] = mlx_load_png("./Gohan/Pod1.png");
	texture[15] = mlx_load_png("./Gohan/Pod2.png");
	while (i < 16)
	{
		if (!texture[i])
			error();
		i++;
	}
	return (texture);
}

mlx_image_t	**ft_load_imgs_est(t_p **vars)
{
	(*vars)->imge = malloc(4 * sizeof(mlx_image_t *));
	(*vars)->imge[0] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[12]);
	(*vars)->imge[1] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[13]);
	(*vars)->imge[2] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[14]);
	(*vars)->imge[3] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[15]);
	if (!(*vars)->imge[0])
		error();
	return ((*vars)->imge);
}

mlx_image_t	**ft_load_imgs_din(t_p **vars)
{
	int	i;

	i = 0;
	(*vars)->imgd = malloc(12 * sizeof(mlx_image_t *));
	while (i < 12)
	{
		(*vars)->imgd[i] = mlx_texture_to_image \
		((*vars)->mlx, (*vars)->texture[i]);
		if (!(*vars)->imgd[i])
			error();
		i++;
	}
	return ((*vars)->imgd);
}
