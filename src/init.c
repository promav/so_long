/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:24:08 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 18:13:47 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_p	*init_vars(void)
{
	t_p	*vars;

	vars = (t_p *)malloc(sizeof(t_p));
	if (!vars)
		exit (EXIT_FAILURE);
	vars->mlx = NULL;
	vars->map = NULL;
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
	char	*addres;

	i = 0;
	names = (char **)malloc(12 * sizeof(char *));
	while (i < 12)
	{
		num = ft_itoa(i);
		addres = ft_strjoin("./images/Gohan", num);
		free(num);
		names[i] = ft_strjoin(addres, ".png");
		free(addres);
		i++;
	}
	return (names);
}

mlx_texture_t	**ft_load_textures(char **names)
{
	mlx_texture_t	**texture;
	int				i;

	i = 0;
	texture = (mlx_texture_t **)malloc(17 * sizeof(mlx_texture_t *));
	while (i < 12)
	{
		texture[i] = mlx_load_png(names[i]);
		i++;
	}
	texture[12] = mlx_load_png("./images/Ground.png");
	texture[13] = mlx_load_png("./images/BD.png");
	texture[14] = mlx_load_png("./images/Pod1.png");
	texture[15] = mlx_load_png("./images/Pod2.png");
	texture[16] = mlx_load_png("./images/Wall.png");
	while (i < 17)
	{
		if (!texture[i])
			error();
		i++;
	}
	return (texture);
}

mlx_image_t	**ft_load_imgs_est(t_p **vars)
{
	(*vars)->imge = malloc(5 * sizeof(mlx_image_t *));
	(*vars)->imge[0] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[12]);
	(*vars)->imge[1] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[13]);
	(*vars)->imge[2] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[14]);
	(*vars)->imge[3] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[15]);
	(*vars)->imge[4] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[16]);
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
