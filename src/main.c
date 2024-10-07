/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:24:25 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/07 10:35:56 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_loading_all(t_p *vars, char **files, t_map map_coor)
{
	vars->texture = ft_load_textures(files);
	vars->imgd = ft_load_imgs_din(&vars);
	vars->imge = ft_load_imgs_est(&vars);
	ft_images_to_window(&vars, map_coor);
}

void	ft_free_files(char **files)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		free(files[i]);
		i++;
	}
	free(files);
}

void	ft_try_openfile(char **argv)
{
	int	fd;
	int	i;

	i = ft_strlen(argv[1]) - 4;
	if (argv[1][i] != '.' || argv[1][i + 1] != 'b' \
	|| argv[1][i + 2] != 'e' || argv[1][i + 3] != 'r')
	{
		ft_printf("The file extension is not correct.\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("The file doesnt exist or you dont have permissions.\n");
		exit(EXIT_FAILURE);
	}
}

int32_t	main(int argc, char **argv)
{
	t_p		vars;
	mlx_t	*mlx;
	char	**files;
	t_map	map_coor;

	if (argc != 2)
		return (EXIT_FAILURE);
	ft_try_openfile(argv);
	vars = init_vars();
	map_coor = map_init(&vars, argv);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(map_coor.columns * 128, \
	map_coor.rows * 128, "So_long", true);
	if (!mlx)
		error();
	vars.mlx = mlx;
	files = file_names();
	ft_loading_all(&vars, files, map_coor);
	ft_free_files(files);
	mlx_loop_hook(mlx, ft_hook, &vars);
	mlx_loop(mlx);
	ending_game(mlx, &vars);
}
