/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:53:55 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:53:56 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->vars.posx + data->vars.dirx * data->vars.movespeed);
	y = (int)data->vars.posy;
	if (data->map[y][x] != '1')
		data->vars.posx += data->vars.dirx * data->vars.movespeed;
	x = (int)data->vars.posx;
	y = (int)(data->vars.posy + data->vars.diry * data->vars.movespeed);
	if (data->map[y][x] != '1')
		data->vars.posy += data->vars.diry * data->vars.movespeed;
}

void	move_backward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->vars.posx - data->vars.dirx * data->vars.movespeed);
	y = (int)data->vars.posy;
	if (data->map[y][x] != '1')
		data->vars.posx -= data->vars.dirx * data->vars.movespeed;
	x = (int)data->vars.posx;
	y = (int)(data->vars.posy - data->vars.diry * data->vars.movespeed);
	if (data->map[y][x] != '1')
		data->vars.posy -= data->vars.diry * data->vars.movespeed;
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->vars.posx - data->vars.planex * data->vars.movespeed);
	y = (int)data->vars.posy;
	if (data->map[y][x] != '1')
		data->vars.posx -= data->vars.planex * data->vars.movespeed;
	x = (int)data->vars.posx;
	y = (int)(data->vars.posy - data->vars.planey * data->vars.movespeed);
	if (data->map[y][x] != '1')
		data->vars.posy -= data->vars.planey * data->vars.movespeed;
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->vars.posx + data->vars.planex * data->vars.movespeed);
	y = (int)data->vars.posy;
	if (data->map[y][x] != '1')
		data->vars.posx += data->vars.planex * data->vars.movespeed;
	x = (int)data->vars.posx;
	y = (int)(data->vars.posy + data->vars.planey * data->vars.movespeed);
	if (data->map[y][x] != '1')
		data->vars.posy += data->vars.planey * data->vars.movespeed;
}
