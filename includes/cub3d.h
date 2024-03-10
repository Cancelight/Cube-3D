/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:57:03 by agaygisi          #+#    #+#             */
/*   Updated: 2024/01/02 15:57:04 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft.h"
# include "../mlx/mlx.h"
# include "./get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WDT 960
# define HGT 540

# define TXSIZE 64

// # define ESC 65307
// # define A 97
// # define D 100
// # define S 115
// # define W 119
// # define L 65361
// # define R 65363

# define ESC 53
# define A 0
# define D 2
# define S 1
# define W 13
# define L 123
# define R 124

typedef struct s_vars
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	frametime;
	double	movespeed;
	double	rotspeed;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	wallx;
	int		mapx;
	int		mapy;
	int		hit;
	int		stepx;
	int		stepy;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	int		texx;
	int		texy;
	long	color;
}			t_vars;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		l;
	int		r;
}			t_keys;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*xpm[5];
	char	*fc[3];
	char	**map;
	t_img	img;
	t_img	tex[5];
	int		texarr[4][TXSIZE * TXSIZE];
	int		resx;
	int		resy;
	int		floor;
	int		ceiling;
	t_vars	vars;
	t_keys	keys;
}			t_data;

// utils
int			len2d(char **arr);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
char		*pass_ws(char *line);
int			count_char(char *str, char c);

void		error(t_data *data, char *str);
void		exit_game(t_data *data);
void		free2d(char **arr);

void		parse(t_data *data, char *cub_file);
int			parse_details(t_data *data, int fd);
int			parse_map(t_data *data, int fd, char *line, int on_map);
void		init_player(t_data *data, int x, int y, char dir);

void		check(t_data *data);
int			check_texture(t_data *data);
int			check_fc(t_data *data);

int			ft_isnum(char *str);

// calculation
void		raycast(t_data *data);
void		raycast_2(t_data *data);
void		raycast_3(t_data *data);

void		move(t_data *data);
void		move_forward(t_data *data);
void		move_backward(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
int			key_press(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);
#endif
