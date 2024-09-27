/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:33:03 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/27 15:36:00 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include <MLX42/include/MLX42/MLX42.h>

#define WIDTH 1920
#define HEIGHT 1280
#define DELAY 10

typedef struct parameters
{
    mlx_t				*mlx;
    mlx_texture_t		**texture;
    mlx_image_t			**imgd;
    mlx_image_t			**imge;
    int					p;
    int					open_door;
    int					x;
    int					y;
    int					e_x;
    int					e_y;
    int					step;
    int					speed;
    struct parameters	*next;
}	t_p;

void			error(void);
t_p				*init_vars(mlx_t *mlx);
char			**file_names(void);
mlx_texture_t	**ft_load_textures(char **names);
mlx_image_t		**ft_load_imgs_est(t_p **vars);
mlx_image_t		**ft_load_imgs_din(t_p **vars);
void			change_image(t_p **vars, int img);
void			move_up(t_p **vars);
void			move_down(t_p **vars);
void			move_left(t_p **vars);
void			move_right(t_p **vars);
void			collectable_control(t_p **vars);
void			rest_position(t_p **vars);
void			ft_hook(void *param);
void			ending_game(mlx_t *mlx, t_p **vars, char **files);

#endif