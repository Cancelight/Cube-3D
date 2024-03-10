/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:56:26 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:56:27 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_perpwalldist(t_data *data)
{
	if (data->vars.side == 0)
		data->vars.perpwalldist = data->vars.sidedistx - data->vars.deltadistx;
	else
		data->vars.perpwalldist = data->vars.sidedisty - data->vars.deltadisty;
}

void	set_lineheight(t_data *data)
{
	data->vars.lineheight = (int)(HGT / data->vars.perpwalldist);
}

void	set_drawstart_drawend(t_data *data)
{
	data->vars.drawstart = (HGT / 2) - (data->vars.lineheight / 2);
	if (data->vars.drawstart < 0)
		data->vars.drawstart = 0;
	data->vars.drawend = (HGT / 2) + (data->vars.lineheight / 2);
	if (data->vars.drawend >= HGT)
		data->vars.drawend = HGT - 1;
}

void	set_texx(t_data *data)
{
	if (data->vars.side == 0)
		data->vars.wallx = data->vars.posy + data->vars.perpwalldist
			* data->vars.raydiry;
	else
		data->vars.wallx = data->vars.posx + data->vars.perpwalldist
			* data->vars.raydirx;
	data->vars.wallx -= floor((data->vars.wallx));
	data->vars.texx = (int)(data->vars.wallx * (double)TXSIZE);
	if (data->vars.side == 0 && data->vars.raydirx > 0)
		data->vars.texx = TXSIZE - data->vars.texx - 1;
	if (data->vars.side == 1 && data->vars.raydiry < 0)
		data->vars.texx = TXSIZE - data->vars.texx - 1;
}

void	raycast_3(t_data *data)
{
	set_perpwalldist(data);
	set_lineheight(data);
	set_drawstart_drawend(data);
	set_texx(data);
}
