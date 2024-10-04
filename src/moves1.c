/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:24:40 by pabromer          #+#    #+#             */
/*   Updated: 2024/10/04 13:03:00 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_image(t_p **vars, int img)
{
	(*vars)->x = (*vars)->imgd[(*vars)->p]->instances[0].x;
	(*vars)->y = (*vars)->imgd[(*vars)->p]->instances[0].y;
	(*vars)->imgd[(*vars)->p]->instances[0].x = -10000;
	(*vars)->imgd[(*vars)->p]->instances[0].y = -10000;
	(*vars)->p = img;
	(*vars)->imgd[(*vars)->p]->instances[0].x = (*vars)->x;
	(*vars)->imgd[(*vars)->p]->instances[0].y = (*vars)->y;
}

void	move_up(t_p **vars)
{
	if ((*vars)->speed == 0)
	{
		if ((*vars)->step % 2 == 0)
		{
			change_image(vars, 10);
			(*vars)->imgd[(*vars)->p]->instances[0].y -= 128;
			(*vars)->step++;
			ft_printf("Steps: %i\n", (*vars)->step);
		}
		else if ((*vars)->step % 2 == 1)
		{
			change_image(vars, 11);
			(*vars)->imgd[(*vars)->p]->instances[0].y -= 128;
			(*vars)->step++;
			ft_printf("Steps: %i\n", (*vars)->step);
		}
		(*vars)->speed = DELAY;
	}
	else
		(*vars)->speed--;
	collectable_control(vars);
}

void	move_down(t_p **vars)
{
	if ((*vars)->speed == 0)
	{
		if ((*vars)->step % 2 == 0)
		{
			change_image(vars, 1);
			(*vars)->imgd[(*vars)->p]->instances[0].y += 128;
			(*vars)->step++;
			ft_printf("Steps: %i\n", (*vars)->step);
		}
		else if ((*vars)->step % 2 == 1)
		{
			change_image(vars, 2);
			(*vars)->imgd[(*vars)->p]->instances[0].y += 128;
			(*vars)->step++;
			ft_printf("Steps: %i\n", (*vars)->step);
		}
		(*vars)->speed = DELAY;
	}
	else
		(*vars)->speed--;
	collectable_control(vars);
}

void	move_left(t_p **vars)
{
	if ((*vars)->speed == 0)
	{
		if ((*vars)->step % 2 == 0)
		{
			change_image(vars, 4);
			(*vars)->imgd[(*vars)->p]->instances[0].x -= 128;
			(*vars)->step++;
			ft_printf("Steps: %i\n", (*vars)->step);
		}
		else if ((*vars)->step % 2 == 1)
		{
			change_image(vars, 5);
			(*vars)->imgd[(*vars)->p]->instances[0].x -= 128;
			(*vars)->step++;
			ft_printf("Steps: %i\n", (*vars)->step);
		}
		(*vars)->speed = DELAY;
	}
	else
		(*vars)->speed--;
	collectable_control(vars);
}

void	move_right(t_p **vars)
{
	if ((*vars)->speed == 0)
	{
		if ((*vars)->step % 2 == 0)
		{
			change_image(vars, 8);
			(*vars)->imgd[(*vars)->p]->instances[0].x += 128;
			(*vars)->step++;
			ft_printf("Steps: %i\n", (*vars)->step);
		}
		else if ((*vars)->step % 2 == 1)
		{
			change_image(vars, 7);
			(*vars)->imgd[(*vars)->p]->instances[0].x += 128;
			(*vars)->step++;
			ft_printf("Steps: %i\n", (*vars)->step);
		}
		(*vars)->speed = DELAY;
	}
	else
		(*vars)->speed--;
	collectable_control(vars);
}
