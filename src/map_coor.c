/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:37:31 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 17:25:12 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_p_coor(t_map *map_coor, int i, int j)
{
	map_coor->p_y = i;
	map_coor->p_x = j;
}

void	ft_e_coor(t_map *map_coor, int i, int j)
{
	map_coor->e_y = i;
	map_coor->e_x = j;
}

int	ft_c_coor(t_map *map_coor, int i, int j, int k)
{
	map_coor->c_y[k] = i;
	map_coor->c_x[k] = j;
	return (1);
}

void	ft_num_medals(t_p **vars, t_map *map_coor)
{
	int	i;
	int	j;

	map_coor->n_colec = 0;
	i = 0;
	while ((*vars)->map[i])
	{
		j = 0;
		while ((*vars)->map[i][j] != '\0')
		{
			if ((*vars)->map[i][j] == 'C')
				map_coor->n_colec++;
			j++;
		}
		i++;
	}
}

void	ft_c_mallocs(t_map *map_coor)
{
	map_coor->c_x = (int *)malloc(map_coor->n_colec * sizeof(int));
	if (!map_coor->c_x)
		return ;
	map_coor->c_y = (int *)malloc(map_coor->n_colec * sizeof(int));
	if (!map_coor->c_y)
		return ;
}
