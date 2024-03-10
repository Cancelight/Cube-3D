/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:50:24 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:50:25 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	paint_base(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HGT)
	{
		while (x < WDT)
		{
			if (y < HGT / 2)
				my_mlx_pixel_put(data, x, y, data->ceiling);
			else
				my_mlx_pixel_put(data, x, y, data->floor);
			x++;
		}
		x = 0;
		y++;
	}
}

int	launch_game(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WDT, HGT);
	data->img.addr = (int *)mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	paint_base(data);
	raycast(data);
	move(data);
	data->vars.frametime = 0.03;
	data->vars.movespeed = data->vars.frametime * 2.0;
	data->vars.rotspeed = data->vars.frametime * 2.0;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	return (0);
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = 0;
	ft_bzero(data->xpm, 5);
	ft_bzero(data->fc, 3);
	data->map = 0;
	data->floor = 0;
	data->ceiling = 0;
	data->keys.w = 0;
	data->keys.a = 0;
	data->keys.s = 0;
	data->keys.d = 0;
	data->keys.l = 0;
	data->keys.r = 0;
	data->vars.posx = 0.5;
	data->vars.posy = 0.5;
}

int	close_window(t_data *data)
{
	exit_game(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		error(&data, "Invalid usage\n./cub3D <map.cub>");
	init(&data);
	parse(&data, argv[1]);
	check(&data);
	data.win = mlx_new_window(data.mlx, WDT, HGT, "cub3D");
	mlx_loop_hook(data.mlx, &launch_game, &data);
	mlx_hook(data.win, 2, 1L << 0, &key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, &key_release, &data);
	mlx_hook(data.win, 17, 1L << 17, &close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
