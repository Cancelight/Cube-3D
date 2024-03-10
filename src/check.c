/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:49:32 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:49:38 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_player(t_data *data)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("NSEW", data->map[y][x]))
			{
				init_player(data, x, y, data->map[y][x]);
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_cells(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("01NSEW ", data->map[y][x]) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_around(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0' || (data->map[i][j] != '1'
			&& data->map[i][j] != ' '))
	{
		if (i == 0 || !data->map[i + 1] || j == 0 || !data->map[i][j + 1])
			return (0);
		if (data->map[i - 1] && data->map[i - 1][j] && data->map[i
			- 1][j] == ' ')
			return (0);
		if (data->map[i + 1] && data->map[i + 1][j] && data->map[i
			+ 1][j] == ' ')
			return (0);
		if (data->map[i] && data->map[i][j - 1] && data->map[i][j - 1] == ' ')
			return (0);
		if (data->map[i] && data->map[i][j + 1] && data->map[i][j + 1] == ' ')
			return (0);
	}
	return (1);
}

int	check_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (len2d(data->map) < 3)
		return (0);
	if (!check_cells(data))
		return (0);
	if (!check_player(data))
		return (0);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (!check_around(data, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	check(t_data *data)
{
	if (!check_texture(data))
		error(data, "Invalid textures");
	if (!check_fc(data))
		error(data, "Invalid floor/ceiling colors");
	if (!check_map(data))
		error(data, "Invalid map");
}
