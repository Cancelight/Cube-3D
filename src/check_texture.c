/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:50:15 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:50:18 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_texarr(t_data *data, int i)
{
	int	x;
	int	y;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			data->texarr[i][64 * y + x] = data->tex[i].addr[64 * y + x];
			x++;
		}
		y++;
	}
}

int	check_texture(t_data *data)
{
	int	i;
	int	texsize;

	i = 0;
	texsize = 64;
	while (i < 4)
	{
		data->tex[i].img = mlx_xpm_file_to_image(data->mlx, data->xpm[i],
				&texsize, &texsize);
		if (!data->tex[i].img)
			return (0);
		data->tex[i].addr = (int *)mlx_get_data_addr(data->tex[i].img,
				&data->tex[i].bits_per_pixel, &data->tex[i].line_length,
				&data->tex[i].endian);
		if (!data->tex[i].addr)
			return (0);
		fill_texarr(data, i);
		mlx_destroy_image(data->mlx, data->tex[i].img);
		i++;
	}
	return (1);
}
