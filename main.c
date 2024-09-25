#include "so_long.h"

static mlx_image_t     **img;
static int  p = 0;
static int  a = 0;
static int  b = 0;


static void error(void)
{
    puts(mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}

mlx_texture_t **ft_load_textures()
{
    mlx_texture_t   **texture;
    int i;

    i = 0;
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
    while(i < 12)
    {
        if(!texture[i])
            error();
        i++;
    }
    return (texture);
}

mlx_image_t **ft_load_imgs(t_p **vars)
{
    int i;

    i = 0;
    (*vars)->img = malloc(12*sizeof(mlx_image_t *));
    while(i < 12)
    {
        (*vars)->img[i] = mlx_texture_to_image((*vars)->mlx, (*vars)->texture[i]);
        if(!(*vars)->img[i])
            error();
        i++;
    }
    return ((*vars)->img);
}
void    ft_hook(void* param)
{
    mlx_t *mlx = param;
    
    if(mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
    else if(mlx_is_key_down(mlx, MLX_KEY_UP) && img[p]->instances[0].y > 0)
    {
        if(p != 9)
        {
            a = img[p]->instances[0].x;
            b = img[p]->instances[0].y;
            img[p]->instances[0].x = -10000;
            img[p]->instances[0].y = -10000;
            p = 9;
            img[p]->instances[0].x = a;
            img[p]->instances[0].y = b;
        }
        img[p]->instances[0].y -= 5;
    }
    else if(mlx_is_key_down(mlx, MLX_KEY_DOWN) && img[p]->instances[0].y < 200)
    {
        if(p != 0)
        {
            a = img[p]->instances[0].x;
            b = img[p]->instances[0].y;
            img[p]->instances[0].x = -10000;
            img[p]->instances[0].y = -10000;
            p = 0;
            img[p]->instances[0].x = a;
            img[p]->instances[0].y = b;
        }
        img[p]->instances[0].y += 5;
    }
    else if(mlx_is_key_down(mlx, MLX_KEY_LEFT) && img[p]->instances[0].x > 0)
    {
        if(p != 3)
        {
            a = img[p]->instances[0].x;
            b = img[p]->instances[0].y;
            img[p]->instances[0].x = -10000;
            img[p]->instances[0].y = -10000;
            p = 3;
            img[p]->instances[0].x = a;
            img[p]->instances[0].y = b;
        }
        img[p]->instances[0].x -= 5;
    }
    else if(mlx_is_key_down(mlx, MLX_KEY_RIGHT) && img[p]->instances[0].x < 500)
    {
        if(p != 6)
        {
            a = img[p]->instances[0].x;
            b = img[p]->instances[0].y;
            img[p]->instances[0].x = -10000;
            img[p]->instances[0].y = -10000;
            p = 6;
            img[p]->instances[0].x = a;
            img[p]->instances[0].y = b;
        }
        img[p]->instances[0].x += 5;
    }
}

void    ft_images_to_window(t_p **vars)
{
    int i;

    i = 1;
    if(mlx_image_to_window((*vars)->mlx, (*vars)->img[0], 0, 0) == -1)
        error();
    while(i < 12)
    {
        if(mlx_image_to_window((*vars)->mlx, (*vars)->img[i], -10000, -10000) == -1)
            error();
        i++;
    }
}

int32_t main(void)
{
    t_p *vars;
    int i;
    mlx_t *mlx;
    
    i = 0;
    mlx = mlx_init(WIDTH, HEIGHT, "So_long", false);
    vars->mlx = mlx;
    if (!mlx)
        error();
    vars->texture = ft_load_textures();
    img = ft_load_imgs(&vars);
    ft_images_to_window(&vars);
    mlx_loop_hook(vars->mlx, ft_hook, vars);
    mlx_loop(mlx);
    while(i < 12)
    {
        mlx_delete_image(mlx, vars->img[p]);
        mlx_delete_texture(vars->texture[p]);
        i++;
    }
    free(vars->texture);
    free(vars->img);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
