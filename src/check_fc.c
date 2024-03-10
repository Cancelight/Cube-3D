/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:49:57 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:50:56 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	convert_rgb(int red, int green, int blue)
{
	int	alpha;
	int	color;

	alpha = 0;
	color = (alpha << 24) | (red << 16) | (green << 8) | blue;
	return (color);
}

void	set_rgb(t_data *data, int *rgb, int i)
{
	if (i == 0)
		data->floor = convert_rgb(rgb[0], rgb[1], rgb[2]);
	else
		data->ceiling = convert_rgb(rgb[0], rgb[1], rgb[2]);
}

int	check_rgb(char **arr, int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!ft_isnum(arr[i]))
			return (0);
		rgb[i] = ft_atoi(arr[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

char	**trim_rgb(char **arr)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!arr)
		return (0);
	if (len2d(arr) != 3)
	{
		free2d(arr);
		return (0);
	}
	while (arr[i])
	{
		tmp = ft_strtrim(arr[i], " \n");
		free(arr[i]);
		arr[i] = tmp;
		i++;
	}
	return (arr);
}

int	check_fc(t_data *data)
{
	int		i;
	char	**arr;
	int		rgb[3];

	i = 0;
	while (i < 2)
	{
		if (count_char(data->fc[i], ',') != 2)
			return (0);
		arr = trim_rgb(ft_split(data->fc[i], ','));
		if (!arr)
			return (0);
		if (!check_rgb(arr, rgb))
		{
			free2d(arr);
			return (0);
		}
		set_rgb(data, rgb, i);
		free2d(arr);
		i++;
	}
	return (1);
}
