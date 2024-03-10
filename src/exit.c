/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:53:25 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:53:26 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>
#include <stdlib.h>

void	free2d(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	exit_game(t_data *data)
{
	if (data->map)
		free2d(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	data = 0;
	exit(0);
}

void	error(t_data *data, char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit_game(data);
}
