/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_details.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:55:54 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:55:55 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_fc(t_data *data, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		line += 2;
		if (data->fc[0] != 0)
			error(data, "Invalid map file\nDuplicate floor color");
		data->fc[0] = ft_strtrim(line, " \n");
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		line += 2;
		if (data->fc[1] != 0)
			error(data, "Invalid map file\nDuplicate ceiling color");
		data->fc[1] = ft_strtrim(line, " \n");
	}
}

void	parse_texture_2(t_data *data, char *line)
{
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		line += 3;
		if (data->xpm[1] != 0)
			error(data, "Invalid map file\nDuplicate west texture");
		data->xpm[1] = ft_strtrim(line, " \n");
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		line += 3;
		if (data->xpm[3] != 0)
			error(data, "Invalid map file\nDuplicate east texture");
		data->xpm[3] = ft_strtrim(line, " \n");
	}
}

void	parse_texture(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		line += 3;
		if (data->xpm[2] != 0)
			error(data, "Invalid map file\nDuplicate north texture");
		data->xpm[2] = ft_strtrim(line, " \n");
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		line += 3;
		if (data->xpm[0] != 0)
			error(data, "Invalid map file\nDuplicate south texture");
		data->xpm[0] = ft_strtrim(line, " \n");
	}
	else
		parse_texture_2(data, line);
}

void	parse_line(t_data *data, char *line)
{
	if (line && ft_strlen(line) > 2 && (ft_strncmp(pass_ws(line), "F ", 2) == 0
			|| ft_strncmp(pass_ws(line), "C ", 2) == 0))
		parse_fc(data, pass_ws(line));
	else
	{
		parse_texture(data, pass_ws(line));
	}
}

int	parse_details(t_data *data, int fd)
{
	char	*line;

	while (len2d(data->xpm) != 4 || len2d(data->fc) != 2)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		if (ft_strlen(line) == 1 || ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		parse_line(data, line);
		free(line);
	}
	return (1);
}
