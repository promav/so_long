/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:15:17 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 17:10:33 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(t_p **vars, int rows)
{
	if (ft_is_rectangular((*vars)->map) == -1)
		ft_printf("Error: The map is not a rectangle.\n");
	if (ft_borders_are_wall((*vars)->map) == -1)
		ft_printf("Error: All the borders are not wall.\n");
	if (ft_allowed_elements((*vars)->map) == -1)
		ft_printf("Error: The map has not allowed elements.\n");
	if (ft_number_of_elements((*vars)->map) == -1)
		ft_printf("Error: The number of allowed elements is not correct.\n");
	if (flood_fill(rows) == -1)
		ft_printf("Error: The map could not be solve.\n");
	if (ft_is_rectangular((*vars)->map) == 0 \
	&& ft_borders_are_wall((*vars)->map) == 0 \
	&& ft_allowed_elements((*vars)->map) == 0 \
	&& ft_number_of_elements((*vars)->map) == 0 \
	&& flood_fill(rows) == 0)
		return (0);
	return (-1);
}

char	**ft_copy_map(int rows)
{
	int		fd;
	int		i;
	int		j;
	char	**map2;

	i = rows;
	map2 = (char **)malloc((1 + i) * sizeof(char *));
	fd = open("maps/map.br", O_RDONLY);
	if (fd == -1)
		return (NULL);
	j = 0;
	while (j < i)
	{
		map2[j] = get_next_line(fd);
		map2[j][ft_strlen(map2[j]) - 1] = '\0';
		j++;
	}
	map2[j] = NULL;
	close(fd);
	return (map2);
}

void	fill(char **map2, int y, int x, char flood)
{
	if (map2[y][x] == '1' || map2[y][x] == '\0' || map2[y][x] == 'F')
		return ;
	map2[y][x] = flood;
	fill(map2, y + 1, x, flood);
	fill(map2, y, x + 1, flood);
	fill(map2, y - 1, x, flood);
	fill(map2, y, x - 1, flood);
}

int	flood_fill(int rows)
{
	char	**map2;
	char	flood;
	int		x;
	int		y;

	map2 = ft_copy_map(rows);
	x = ft_find_px(map2);
	y = ft_find_py(map2);
	flood = 'F';
	fill(map2, y, x, flood);
	x = 0;
	while (map2[x])
	{
		y = 0;
		while (map2[x][y] != '\0')
		{
			if (map2[x][y] == 'C' || map2[x][y] == 'E')
				return (-1);
			y++;
		}
		x++;
	}
	ft_free_map2(map2);
	return (0);
}
