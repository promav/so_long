/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:10:41 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 17:14:42 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_px(char **map2)
{
	int	x;
	int	y;

	y = 0;
	while (map2[y])
	{
		x = 0;
		while (map2[y][x])
		{
			if (map2[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_find_py(char **map2)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map2[y])
	{
		x = 0;
		while (map2[y][x])
		{
			if (map2[y][x] == 'P')
			{
				i = 1;
				break ;
			}
			x++;
		}
		if (i == 1)
			return (y);
		y++;
	}
	return (0);
}

void	ft_free_map2(char **map2)
{
	int	y;

	y = 0;
	while (map2[y])
	{
		free(map2[y]);
		y++;
	}
	free(map2);
}
