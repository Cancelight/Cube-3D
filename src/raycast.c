/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:56:20 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:56:20 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_raydir(t_data *data, int x)
{
	data->vars.camerax = 2 * x / (double)WDT - 1;
	data->vars.raydirx = data->vars.dirx + data->vars.planex
		* data->vars.camerax;
	data->vars.raydiry = data->vars.diry + data->vars.planey
		* data->vars.camerax;
}

void	set_box_position(t_data *data)
{
	data->vars.mapx = (int)data->vars.posx;
	data->vars.mapy = (int)data->vars.posy;
	data->vars.hit = 0;
}

void	set_delta_dist(t_data *data)
{
	if (data->vars.raydirx == 0)
		data->vars.deltadistx = 0;
	else
		data->vars.deltadistx = fabs(1 / data->vars.raydirx);
	if (data->vars.raydiry == 0)
		data->vars.deltadisty = 0;
	else
		data->vars.deltadisty = fabs(1 / data->vars.raydiry);
}

void	draw_box_texture(t_data *data, int x)
{
	double	step;
	double	texpos;
	int		y;

	step = 1.0 * TXSIZE / data->vars.lineheight;
	texpos = (data->vars.drawstart - (double)HGT / 2
			+ (double)data->vars.lineheight / 2) * step;
	y = data->vars.drawstart;
	while (y < data->vars.drawend)
	{
		data->vars.texy = (int)texpos & (TXSIZE - 1);
		texpos += step;
		data->vars.color = data->texarr[data->vars.texnum][TXSIZE
			* data->vars.texy + data->vars.texx];
		if (data->vars.side == 1)
			data->vars.color = (data->vars.color >> 1) & 8355711;
		my_mlx_pixel_put(data, x, y, data->vars.color);
		y++;
	}
}

void	raycast(t_data *data)
{
	int	x;

	x = 0;
	while (x < WDT)
	{
		set_raydir(data, x);
		set_box_position(data);
		set_delta_dist(data);
		raycast_2(data);
		raycast_3(data);
		draw_box_texture(data, x);
		x++;
	}
}
