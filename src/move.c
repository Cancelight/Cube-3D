/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:53:43 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:53:51 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->vars.dirx;
	data->vars.dirx = data->vars.dirx * cos(data->vars.rotspeed)
		- data->vars.diry * sin(data->vars.rotspeed);
	data->vars.diry = old_dir_x * sin(data->vars.rotspeed) + data->vars.diry
		* cos(data->vars.rotspeed);
	old_plane_x = data->vars.planex;
	data->vars.planex = data->vars.planex * cos(data->vars.rotspeed)
		- data->vars.planey * sin(data->vars.rotspeed);
	data->vars.planey = old_plane_x * sin(data->vars.rotspeed)
		+ data->vars.planey * cos(data->vars.rotspeed);
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->vars.dirx;
	data->vars.dirx = data->vars.dirx * cos(-data->vars.rotspeed)
		- data->vars.diry * sin(-data->vars.rotspeed);
	data->vars.diry = old_dir_x * sin(-data->vars.rotspeed) + data->vars.diry
		* cos(-data->vars.rotspeed);
	old_plane_x = data->vars.planex;
	data->vars.planex = data->vars.planex * cos(-data->vars.rotspeed)
		- data->vars.planey * sin(-data->vars.rotspeed);
	data->vars.planey = old_plane_x * sin(-data->vars.rotspeed)
		+ data->vars.planey * cos(-data->vars.rotspeed);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_game(data);
	else if (keycode == W)
		data->keys.w = 1;
	else if (keycode == A)
		data->keys.a = 1;
	else if (keycode == S)
		data->keys.s = 1;
	else if (keycode == D)
		data->keys.d = 1;
	else if (keycode == L)
		data->keys.l = 1;
	else if (keycode == R)
		data->keys.r = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->keys.w = 0;
	else if (keycode == A)
		data->keys.a = 0;
	else if (keycode == S)
		data->keys.s = 0;
	else if (keycode == D)
		data->keys.d = 0;
	else if (keycode == L)
		data->keys.l = 0;
	else if (keycode == R)
		data->keys.r = 0;
	return (0);
}

void	move(t_data *data)
{
	if (data->keys.w == 1)
		move_forward(data);
	if (data->keys.s == 1)
		move_backward(data);
	if (data->keys.a == 1)
		move_left(data);
	if (data->keys.d == 1)
		move_right(data);
	if (data->keys.l == 1)
		rotate_left(data);
	if (data->keys.r == 1)
		rotate_right(data);
}
