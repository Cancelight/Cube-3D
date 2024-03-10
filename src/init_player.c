/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:53:30 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:53:31 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player_we(t_data *data, char dir)
{
	if (dir == 'W')
	{
		data->vars.dirx = -1;
		data->vars.diry = 0;
		data->vars.planex = 0;
		data->vars.planey = -0.66;
	}
	else if (dir == 'E')
	{
		data->vars.dirx = 1;
		data->vars.diry = 0;
		data->vars.planex = 0;
		data->vars.planey = 0.66;
	}
}

void	init_player(t_data *data, int x, int y, char dir)
{
	data->vars.posx += x;
	data->vars.posy += y;
	if (dir == 'N')
	{
		data->vars.dirx = 0;
		data->vars.diry = -1;
		data->vars.planex = 0.66;
		data->vars.planey = 0;
	}
	else if (dir == 'S')
	{
		data->vars.dirx = 0;
		data->vars.diry = 1;
		data->vars.planex = -0.66;
		data->vars.planey = 0;
	}
	init_player_we(data, dir);
}
