/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:54:22 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/27 12:45:36 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    collectable_control(t_p **vars)
{
    if(((*vars)->imgd[(*vars)->p]->instances[0].x == (*vars)->imge[1]->instances[0].x) &&  ((*vars)->imgd[(*vars)->p]->instances[0].y == (*vars)->imge[1]->instances[0].y))
    {    
        (*vars)->imge[1]->instances[0].x = -1000;
        (*vars)->open_door = 1;
    }
    if((*vars)->imge[1]->instances[0].x == -1000 && (*vars)->open_door == 1)
    {
        (*vars)->e_x = (*vars)->imge[2]->instances[0].x;
        (*vars)->e_y = (*vars)->imge[2]->instances[0].y;
        (*vars)->imge[3]->instances[0].x = (*vars)->e_x;
        (*vars)->imge[3]->instances[0].y = (*vars)->e_y;
        (*vars)->imge[2]->instances[0].x = -1000;
        (*vars)->open_door = 0;
    }
}

void    rest_position(t_p **vars)
{
    if((*vars)->p == 11 || (*vars)->p == 10)
    {
        change_image(vars, 9);
    }
    if((*vars)->p == 2 || (*vars)->p == 1)
    {
        change_image(vars, 0);
    }
    if((*vars)->p == 5 || (*vars)->p == 4)
    {
        change_image(vars, 3);
    }
    if((*vars)->p == 8 || (*vars)->p == 7)
    {
        change_image(vars, 6);
    }
}

void    ft_hook(void* param)
{
    t_p *vars = param;

    if(mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
        return ;
    else if(mlx_is_key_down(vars->mlx, MLX_KEY_UP) && vars->imgd[vars->p]->instances[0].y > 0)
        move_up(&vars);
    else if(mlx_is_key_down(vars->mlx, MLX_KEY_DOWN) && vars->imgd[vars->p]->instances[0].y < HEIGHT-128)
        move_down(&vars);
    else if(mlx_is_key_down(vars->mlx, MLX_KEY_LEFT) && vars->imgd[vars->p]->instances[0].x > 0)
        move_left(&vars);

    else if(mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT) && vars->imgd[vars->p]->instances[0].x < WIDTH-128)
        move_right(&vars);
    else
        rest_position(&vars);
}
