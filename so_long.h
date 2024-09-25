#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/include/MLX42/MLX42.h>

#define WIDTH 1640
#define HEIGHT 1360

typedef struct parameters
{
    mlx_t               *mlx;
    mlx_texture_t       **texture;
    mlx_image_t         **img;
    int                 p;
    int                 a;
    int                 b;
    struct parameters   *next;
}   t_p;

#endif