/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:56:23 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:56:24 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_step_sidedist_x(t_data *data)
{
	if (data->vars.raydirx < 0)
	{
		data->vars.stepx = -1;
		data->vars.sidedistx = (data->vars.posx - data->vars.mapx)
			* data->vars.deltadistx;
	}
	else
	{
		data->vars.stepx = 1;
		data->vars.sidedistx = (data->vars.mapx + 1.0 - data->vars.posx)
			* data->vars.deltadistx;
	}
}

void	set_step_sidedist_y(t_data *data)
{
	if (data->vars.raydiry < 0)
	{
		data->vars.stepy = -1;
		data->vars.sidedisty = (data->vars.posy - data->vars.mapy)
			* data->vars.deltadisty;
	}
	else
	{
		data->vars.stepy = 1;
		data->vars.sidedisty = (data->vars.mapy + 1.0 - data->vars.posy)
			* data->vars.deltadisty;
	}
}

void	set_texture(t_data *data)
{
	if (data->vars.side == 0)
	{
		if (data->vars.mapx > data->vars.posx)
			data->vars.texnum = 1;
		else
			data->vars.texnum = 3;
	}
	else
	{
		if (data->vars.mapy > data->vars.posy)
			data->vars.texnum = 2;
		else
			data->vars.texnum = 0;
	}
}

void	dda(t_data *data)
{
	while (data->vars.hit == 0)
	{
		if (data->vars.sidedistx < data->vars.sidedisty)
		{
			data->vars.sidedistx += data->vars.deltadistx;
			data->vars.mapx += data->vars.stepx;
			data->vars.side = 0;
		}
		else
		{
			data->vars.sidedisty += data->vars.deltadisty;
			data->vars.mapy += data->vars.stepy;
			data->vars.side = 1;
		}
		if (data->map[data->vars.mapy][data->vars.mapx] == '1')
		{
			data->vars.hit = 1;
			set_texture(data);
		}
	}
}

void	raycast_2(t_data *data)
{
	set_step_sidedist_x(data);
	set_step_sidedist_y(data);
	dda(data);
}
