#include "so_long.h"

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
    texture = malloc(13*sizeof(mlx_texture_t *));
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
    texture[12] = mlx_load_png("./Gohan/Ground.png");
    while(i < 13)
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
    while(i < 13)
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
    t_p *vars = param;
    
    if(mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(vars->mlx);
    else if(mlx_is_key_down(vars->mlx, MLX_KEY_UP) && vars->img[vars->p]->instances[0].y > 0)
    {
        if(vars->speed == 0)
        {
            if(vars->step == 0)
            {
                vars->a = vars->img[vars->p]->instances[0].x;
                vars->b = vars->img[vars->p]->instances[0].y;
                vars->img[vars->p]->instances[0].x = -10000;
                vars->img[vars->p]->instances[0].y = -10000;
                vars->p = 10;
                vars->img[vars->p]->instances[0].x = vars->a;
                vars->img[vars->p]->instances[0].y = vars->b;
                vars->img[vars->p]->instances[0].y -= 128;
                vars->step = 1;
            }
            else if(vars->step == 1)
            {
                vars->a = vars->img[vars->p]->instances[0].x;
                vars->b = vars->img[vars->p]->instances[0].y;
                vars->img[vars->p]->instances[0].x = -10000;
                vars->img[vars->p]->instances[0].y = -10000;
                vars->p = 11;
                vars->img[vars->p]->instances[0].x = vars->a;
                vars->img[vars->p]->instances[0].y = vars->b;
                vars->img[vars->p]->instances[0].y -= 128;
                vars->step = 0;
            }
            vars->speed = DELAY;
        }
        else
            vars->speed--; 
    }
    else if(mlx_is_key_down(vars->mlx, MLX_KEY_DOWN) && vars->img[vars->p]->instances[0].y < HEIGHT-128)
    {
        if(vars->speed == 0)
        {
            if(vars->step == 0)
            {
                vars->a = vars->img[vars->p]->instances[0].x;
                vars->b = vars->img[vars->p]->instances[0].y;
                vars->img[vars->p]->instances[0].x = -10000;
                vars->img[vars->p]->instances[0].y = -10000;
                vars->p = 1;
                vars->img[vars->p]->instances[0].x = vars->a;
                vars->img[vars->p]->instances[0].y = vars->b;
                vars->img[vars->p]->instances[0].y += 128;
                vars->step = 1;
            }
            else if(vars->step == 1)
            {
                vars->a = vars->img[vars->p]->instances[0].x;
                vars->b = vars->img[vars->p]->instances[0].y;
                vars->img[vars->p]->instances[0].x = -10000;
                vars->img[vars->p]->instances[0].y = -10000;
                vars->p = 2;
                vars->img[vars->p]->instances[0].x = vars->a;
                vars->img[vars->p]->instances[0].y = vars->b;
                vars->img[vars->p]->instances[0].y += 128;
                vars->step = 0;
            }
            vars->speed = DELAY;
        }
        else
            vars->speed--;
    }
    else if(mlx_is_key_down(vars->mlx, MLX_KEY_LEFT) && vars->img[vars->p]->instances[0].x > 0)
    {
        if(vars->speed == 0)
        {
            if(vars->step == 0)
            {
                vars->a = vars->img[vars->p]->instances[0].x;
                vars->b = vars->img[vars->p]->instances[0].y;
                vars->img[vars->p]->instances[0].x = -10000;
                vars->img[vars->p]->instances[0].y = -10000;
                vars->p = 4;
                vars->img[vars->p]->instances[0].x = vars->a;
                vars->img[vars->p]->instances[0].y = vars->b;
                vars->img[vars->p]->instances[0].x -= 128;
                vars->step = 1;
            }
            else if(vars->step == 1)
            {
                vars->a = vars->img[vars->p]->instances[0].x;
                vars->b = vars->img[vars->p]->instances[0].y;
                vars->img[vars->p]->instances[0].x = -10000;
                vars->img[vars->p]->instances[0].y = -10000;
                vars->p = 5;
                vars->img[vars->p]->instances[0].x = vars->a;
                vars->img[vars->p]->instances[0].y = vars->b;
                vars->img[vars->p]->instances[0].x -= 128;
                vars->step = 0;
            }
            vars->speed = DELAY;
        }
        else
            vars->speed--;

    }
    else if(mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT) && vars->img[vars->p]->instances[0].x < WIDTH-128)
    {
        if(vars->speed == 0)
        {
            if(vars->step == 0)
            {
                vars->a = vars->img[vars->p]->instances[0].x;
                vars->b = vars->img[vars->p]->instances[0].y;
                vars->img[vars->p]->instances[0].x = -10000;
                vars->img[vars->p]->instances[0].y = -10000;
                vars->p = 7;
                vars->img[vars->p]->instances[0].x = vars->a;
                vars->img[vars->p]->instances[0].y = vars->b;
                vars->img[vars->p]->instances[0].x += 128;
                vars->step = 1;
            }
            else if(vars->step == 1)
            {
                vars->a = vars->img[vars->p]->instances[0].x;
                vars->b = vars->img[vars->p]->instances[0].y;
                vars->img[vars->p]->instances[0].x = -10000;
                vars->img[vars->p]->instances[0].y = -10000;
                vars->p = 8;
                vars->img[vars->p]->instances[0].x = vars->a;
                vars->img[vars->p]->instances[0].y = vars->b;
                vars->img[vars->p]->instances[0].x += 128;
                vars->step = 0;
            }
            vars->speed = DELAY;
        }
        else
            vars->speed--;
    }
    else
    {
        if(vars->p == 11 || vars->p == 10)
        {
            vars->a = vars->img[vars->p]->instances[0].x;
            vars->b = vars->img[vars->p]->instances[0].y;
            vars->img[vars->p]->instances[0].x = -10000;
            vars->img[vars->p]->instances[0].y = -10000;
            vars->p = 9;
            vars->img[vars->p]->instances[0].x = vars->a;
            vars->img[vars->p]->instances[0].y = vars->b;
        }
        if(vars->p == 2 || vars->p == 1)
        {
            vars->a = vars->img[vars->p]->instances[0].x;
            vars->b = vars->img[vars->p]->instances[0].y;
            vars->img[vars->p]->instances[0].x = -10000;
            vars->img[vars->p]->instances[0].y = -10000;
            vars->p = 0;
            vars->img[vars->p]->instances[0].x = vars->a;
            vars->img[vars->p]->instances[0].y = vars->b;
        }
        if(vars->p == 5 || vars->p == 4)
        {
            vars->a = vars->img[vars->p]->instances[0].x;
            vars->b = vars->img[vars->p]->instances[0].y;
            vars->img[vars->p]->instances[0].x = -10000;
            vars->img[vars->p]->instances[0].y = -10000;
            vars->p = 3;
            vars->img[vars->p]->instances[0].x = vars->a;
            vars->img[vars->p]->instances[0].y = vars->b;
        }
        if(vars->p == 8 || vars->p == 7)
        {
            vars->a = vars->img[vars->p]->instances[0].x;
            vars->b = vars->img[vars->p]->instances[0].y;
            vars->img[vars->p]->instances[0].x = -10000;
            vars->img[vars->p]->instances[0].y = -10000;
            vars->p = 6;
            vars->img[vars->p]->instances[0].x = vars->a;
            vars->img[vars->p]->instances[0].y = vars->b;
        }
    }
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
            if(mlx_image_to_window((*vars)->mlx, (*vars)->img[12], 128*i, 128*j) == -1)
            error();
            j++;
        }
        i++;    
    }
    if(mlx_image_to_window((*vars)->mlx, (*vars)->img[0], 0, 0) == -1)
        error();
    i = 0;
    while(i < 12)
    {
        if(mlx_image_to_window((*vars)->mlx, (*vars)->img[i], -10000, -10000) == -1)
            error();
        i++;
    }
}
t_p *init_vars(mlx_t *mlx)
{
        t_p *vars;

        vars = (t_p *)malloc(sizeof(t_p));
        vars->mlx = mlx;
        vars->texture = NULL;
        vars->img = NULL;
        vars->p = 0;
        vars->a = 0;
        vars->b = 0;
        vars->step = 0;
        vars->speed = 0;
        vars->next = NULL;
        return (vars);
}

int32_t main(void)
{
    t_p *vars;
    int i;
    mlx_t *mlx;
    

    mlx = mlx_init(WIDTH, HEIGHT, "So_long", false);
    if (!mlx)
        error();
    vars = init_vars(mlx);
    vars->texture = ft_load_textures();
    vars->img = ft_load_imgs(&vars);
    ft_images_to_window(&vars);
    mlx_loop_hook(mlx, ft_hook, vars);
    mlx_loop(mlx);
    while(i < 12)
    {
        mlx_delete_image(mlx, vars->img[vars->p]);
        mlx_delete_texture(vars->texture[vars->p]);
        i++;
    }
    free(vars->texture);
    free(vars->img);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
