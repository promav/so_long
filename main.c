#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/include/MLX42/MLX42.h>

#define WIDTH 1640
#define HEIGHT 1360

static mlx_image_t     **img;

static void error(void)
{
    puts(mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}

mlx_texture_t **ft_load_textures()
{
    mlx_texture_t   **texture;

    texture = malloc(12*sizeof(mlx_texture_t *));
    texture[0] = mlx_load_png("./Gohan/GohanD0.png");
    texture[1] = mlx_load_png("./Gohan/GohanD1.png");
    texture[2] = mlx_load_png("./Gohan/GohanD2.png");
    texture[3] = mlx_load_png("./Gohan/GohanL0.png");
    texture[4] = mlx_load_png("./Gohan/GohanL1.png");
    texture[5] = mlx_load_png("./Gohan/GohanL2.png");
    texture[6] = mlx_load_png("./Gohan/GohanR0.png");
    texture[7] = mlx_load_png("./Gohan/GohanR1.png");
    texture[8] = mlx_load_png("./Gohan/GohanR2.png");
    texture[9] = mlx_load_png("./Gohan/GohanU0.png");
    texture[10] = mlx_load_png("./Gohan/GohanU1.png");
    texture[11] = mlx_load_png("./Gohan/GohanU2.png");
    if(!texture[0])
        error();
    return (texture);
}

mlx_image_t **ft_load_imgs(mlx_t *mlx, mlx_texture_t **texture)
{
    int i;

    i = 0;
    img = malloc(12*sizeof(mlx_image_t *));
    while(i < 12)
    {
        img[i] = mlx_texture_to_image(mlx, texture[i]);
        if(!img[i])
            error();
        i++;
    }
    return (img);
}
void    ft_hook(void* param)
{
    mlx_t *mlx = param;
    int a;
    int b;

    if(mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
    else if(mlx_is_key_down(mlx, MLX_KEY_UP) && img[0]->instances[0].y > 0)
        img[0]->instances[0].y -= 5;
    else if(mlx_is_key_down(mlx, MLX_KEY_DOWN) && img[0]->instances[0].y < 200)
        img[0]->instances[0].y += 5;
    else if(mlx_is_key_down(mlx, MLX_KEY_LEFT) && img[0]->instances[0].x > 0)
        img[0]->instances[0].x -= 5;
    else if(mlx_is_key_down(mlx, MLX_KEY_RIGHT) && img[0]->instances[0].x < 500)
    {
        if(img[0]->instances[0].x < 500)
        {
            a = img[0]->instances[0].x;
            b = img[0]->instances[0].y;
            mlx_delete_image(mlx, img[0]);
            if (mlx_image_to_window(mlx, img[6], a, b) < 0)
            {
                error();
            }
        }
        img[6]->instances[0].x += 5;
    }
}

void    ft_images_to_window(mlx_t *mlx, mlx_image_t **img)
{
    if(mlx_image_to_window(mlx, img[0], 0, 0) == -1)
        error();
    /*if(mlx_image_to_window(mlx, img[1], 128, 0) == -1)
        error();
    if(mlx_image_to_window(mlx, img[2], 256, 0) == -1)
        error();
    if(mlx_image_to_window(mlx, img[3], 0, 128) == -1)
        error();
    if(mlx_image_to_window(mlx, img[4], 128, 128) == -1)
        error();
    if(mlx_image_to_window(mlx, img[5], 256, 128) == -1)
        error();
    if(mlx_image_to_window(mlx, img[6], 0, 256) == -1)
        error();
    if(mlx_image_to_window(mlx, img[7], 128, 256) == -1)
        error();
    if(mlx_image_to_window(mlx, img[8], 256, 256) == -1)
        error();
    if(mlx_image_to_window(mlx, img[9], 0, 384) == -1)
        error();
    if(mlx_image_to_window(mlx, img[10], 128, 384) == -1)
        error();
    if(mlx_image_to_window(mlx, img[11], 256, 384) == -1)
        error();*/
}

int32_t main(void)
{
    mlx_t           *mlx;
    mlx_texture_t   **texture;
       
    texture = NULL;
    mlx = mlx_init(WIDTH, HEIGHT, "So_long", false);
    if (!mlx)
        error();
    texture = ft_load_textures();
    img = ft_load_imgs(mlx, texture);
    ft_images_to_window(mlx, img);
    mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
    mlx_delete_image(mlx, img[0]);
    mlx_delete_texture(texture[0]);
    free(texture);
    free(img);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
