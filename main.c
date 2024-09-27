/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:24:25 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/27 12:45:58 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(void)
{
    puts(mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}

void    ft_images_to_window(t_p **vars)
{
    int i;
    int j;
    int w;
    int h;

    w = WIDTH / 128;
    h = HEIGHT / 128;
    i = 0;
    while(i < w)
    {
        j = 0;
        while (j < h)
        {
            if(mlx_image_to_window((*vars)->mlx, (*vars)->imge[0], 128*i, 128*j) == -1)
            error();
            j++;
        }
        i++;    
    }
    if(mlx_image_to_window((*vars)->mlx, (*vars)->imgd[0], 128, 128) == -1)
        error();
    i = 0;
    while(i < 12)
    {
        if(mlx_image_to_window((*vars)->mlx, (*vars)->imgd[i], -10000, -10000) == -1)
            error();
        i++;
    }
    if(mlx_image_to_window((*vars)->mlx, (*vars)->imge[1], (w/2)*128, (h/2)*128) == -1)
        error();
    if(mlx_image_to_window((*vars)->mlx, (*vars)->imge[2], (w/4)*128, (h/4)*128) == -1)
        error();
    if(mlx_image_to_window((*vars)->mlx, (*vars)->imge[3], -1000, -1000) == -1)
        error();
    i = 0;
}

int32_t main(void)
{
    t_p *vars;
    mlx_t *mlx;
    char **files;
    
    mlx = mlx_init(WIDTH, HEIGHT, "So_long", false);
    if (!mlx)
        error();
    vars = init_vars(mlx);
    files = file_names();
    vars->texture = ft_load_textures(files);
    vars->imgd = ft_load_imgs_din(&vars);
    vars->imge = ft_load_imgs_est(&vars);
    ft_images_to_window(&vars);
    mlx_loop_hook(mlx, ft_hook, vars);
    mlx_loop(mlx);
    ending_game(mlx, &vars, files);
    mlx_close_window(vars->mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
