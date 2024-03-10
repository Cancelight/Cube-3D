/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:55:57 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:55:58 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_map_line(t_data *data, char *line)
{
	if (data->map == 0)
	{
		data->map = ft_calloc(1024, sizeof(char *));
		if (!data->map)
		{
			free(line);
			error(data, "Invalid map file\nMalloc failed");
		}
		data->map[0] = ft_strtrim(line, "\n");
	}
	else
	{
		data->map[len2d(data->map)] = ft_strtrim(line, "\n");
	}
}

int	longest_line(char **map)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > (size_t)max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	fix_map(t_data *data)
{
	int		i;
	int		max;
	char	*tmp;

	i = 0;
	max = longest_line(data->map);
	while (data->map[i])
	{
		tmp = ft_calloc(max + 1, sizeof(char));
		ft_memset(tmp, ' ', max);
		ft_memcpy(tmp, data->map[i], ft_strlen(data->map[i]));
		free(data->map[i]);
		data->map[i] = tmp;
		i++;
	}
}

int	is_map_line(char *line, int *on_map)
{
	char	*tmp;

	if ((ft_strchr(line, '1') || ft_strchr(line, '0')) && *on_map != 2)
		return (1);
	if ((ft_strchr(line, 'N') || ft_strchr(line, 'S')) && *on_map != 2)
		return (1);
	if ((ft_strchr(line, 'E') || ft_strchr(line, 'W')) && *on_map != 2)
		return (1);
	tmp = ft_strtrim(line, " ");
	if (ft_strlen(tmp) == 1)
	{
		if (*on_map == 1)
			*on_map = 2;
		free(tmp);
		return (2);
	}
	free(tmp);
	return (0);
}

int	parse_map(t_data *data, int fd, char *line, int on_map)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!is_map_line(line, &on_map))
		{
			free(line);
			return (0);
		}
		else if (is_map_line(line, &on_map) == 1)
		{
			if (on_map == 2)
			{
				free(line);
				return (0);
			}
			on_map = 1;
			parse_map_line(data, line);
		}
		free(line);
	}
	if (data->map)
		fix_map(data);
	return (data->map != 0);
}
