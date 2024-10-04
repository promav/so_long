/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:56:26 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 16:51:41 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rectangular(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_borders_are_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (-1);
		j++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_allowed_elements(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' \
			&& map[i][j] != 'E' && map[i][j] != 'P')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_count_elements(char **map)
{
	int		i;
	int		j;
	int		*pec;

	pec = (int *)ft_calloc(3, sizeof(int));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				pec[0]++;
			if (map[i][j] == 'E')
				pec[1]++;
			if (map[i][j] == 'C')
				pec[2]++;
			j++;
		}
		i++;
	}
	return (pec);
}

int	ft_number_of_elements(char **map)
{
	int		*pec;

	pec = ft_count_elements(map);
	if (pec[0] <= 0 || pec[0] > 1)
	{
		free(pec);
		return (-1);
	}
	if (pec[1] <= 0 || pec[1] > 1)
	{
		free(pec);
		return (-1);
	}
	if (pec[2] <= 0)
	{
		free(pec);
		return (-1);
	}
	free(pec);
	return (0);
}
