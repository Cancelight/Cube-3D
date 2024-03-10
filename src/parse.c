/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:55:51 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:55:52 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse(t_data *data, char *cub_file)
{
	int	fd;
	int	len;

	len = ft_strlen(cub_file);
	if (len < 4 || ft_strncmp(cub_file + len - 4, ".cub", 4))
		error(data, "Invalid map file\nFile must be a .cub");
	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
		error(data, "Invalid map file\nCannot open file");
	if (!parse_details(data, fd))
		error(data, "Invalid game details\nMissing texture or color");
	if (!parse_map(data, fd, NULL, 0))
		error(data, "Invalid map file\nMissing/Invalid map");
}
