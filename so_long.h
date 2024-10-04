/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:33:03 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 17:41:58 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <MLX42/include/MLX42/MLX42.h>

# define WIDTH 1920
# define HEIGHT 1280
# define DELAY 5

typedef struct parameters
{
	mlx_t				*mlx;
	char				**map;
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
	int					w;
	int					h;
	int					n_colec;
	int					left_colec;
	struct parameters	*next;
}	t_p;

typedef struct map_elements
{
	int	p_x;
	int	p_y;
	int	e_x;
	int	e_y;
	int	*c_x;
	int	*c_y;
	int	columns;
	int	rows;
	int	n_colec;
}	t_map;

void			error(void);
t_p				*init_vars(void);
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
int				ft_count_rows(char **argv);
int				ft_create_map(t_p **vars, int rows, char **argv);
int				ft_is_rectangular(char **map);
int				ft_borders_are_wall(char **map);
int				ft_allowed_elements(char **map);
int				*ft_count_elements(char **map);
int				ft_number_of_elements(char **map);
void			fill(char **map2, int x, int y, char flood);
int				flood_fill(int rows);
int				map_checker(t_p **vars, int rows);
void			ft_free_map(char **map);
t_map			map_init(t_p **vars, char **argv);
void			ft_images_to_window(t_p **vars, t_map map_coor);
t_map			ft_map_coor(t_p **vars);
void			ft_p_coor(t_map *map_coor, int i, int j);
void			ft_e_coor(t_map *map_coor, int i, int j);
int				ft_c_coor(t_map *map_coor, int i, int j, int k);
void			ft_c_mallocs(t_map *map_coor);
void			ft_num_medals(t_p **vars, t_map *map_coor);
int				ft_find_px(char **map2);
int				ft_find_py(char **map2);
void			ft_free_map2(char **map2);

#endif