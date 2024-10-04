/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:15:17 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 17:42:16 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_rows(char **argv)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

int	ft_create_map(t_p **vars, int r, char **argv)
{
	int	fd;
	int	i;
	int	j;

	i = r;
	(*vars)->map = (char **)malloc((1 + i) * sizeof(char *));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	j = 0;
	while (j < i)
	{
		(*vars)->map[j] = get_next_line(fd);
		if ((*vars)->map[j][ft_strlen((*vars)->map[j]) - 1] == '\n')
			(*vars)->map[j][ft_strlen((*vars)->map[j]) - 1] = '\0';
		j++;
	}
	(*vars)->map[j] = NULL;
	close(fd);
	return (0);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

t_map	map_init(t_p **vars, char **argv)
{
	int		rows;
	t_map	map_coor;

	rows = ft_count_rows(argv);
	ft_create_map(vars, rows, argv);
	flood_fill(rows);
	if (map_checker(vars, rows) == -1)
	{
		if (ft_count_rows(argv) == rows)
		{
			ft_free_map((*vars)->map);
			free(*vars);
			exit (0);
		}
	}
	map_coor = ft_map_coor(vars);
	map_coor.rows = rows;
	map_coor.columns = ft_strlen((*vars)->map[0]);
	return (map_coor);
}

t_map	ft_map_coor(t_p **vars)
{
	t_map	map_coor;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	ft_num_medals(vars, &map_coor);
	ft_c_mallocs(&map_coor);
	while ((*vars)->map[i])
	{
		j = 0;
		while ((*vars)->map[i][j] != '\0')
		{
			if ((*vars)->map[i][j] == 'P')
				ft_p_coor(&map_coor, i, j);
			if ((*vars)->map[i][j] == 'E')
				ft_e_coor(&map_coor, i, j);
			if ((*vars)->map[i][j] == 'C')
				k += ft_c_coor(&map_coor, i, j, k);
			j++;
		}
		i++;
	}
	return (map_coor);
}
