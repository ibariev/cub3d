/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:01:42 by mlatashi          #+#    #+#             */
/*   Updated: 2022/02/05 19:08:40 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "parser.h"

# define PI				3.14159265358979323846
# define W_KEY			119
# define A_KEY			97
# define S_KEY			115
# define D_KEY			100
# define LEFT_ARROW		65361
# define RIGHT_ARROW	65363
# define ESC_KEY		65307	
# define MV_SPEED		0.5
# define SCREEN_W		960
# define SCREEN_H		640
# define TEX_W			64
# define TEX_H			64

typedef struct s_pic
{
	void		*img;
	char		*addr;
	int			size_line;
	int			bpp;
	int			en;
	int			width;
	int			hight;
}					t_pic;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_pic			*img;
	t_pic			tex[4];
	char			**map;
	int				screen[SCREEN_H][SCREEN_W];
	double			px;
	double			py;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perp_wd;
	int				line_height;
	int				start_draw;
	int				end_draw;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			tex_step;
	double			tex_pos;
	unsigned int	color;
	t_info			*pars;
}					t_data;

void			init_all(t_data *data);
void			init_player(t_data *data);
void			init_orientation(t_data *data);
void			draw(t_data *data);
void			draw_ceiling_and_floor(t_data *data);
void			raycast(t_data *data);
void			calc_raydir(t_data *data, int x);
void			calc_wall_dist(t_data *data);
void			find_hit(t_data *data);
void			draw_tex(t_data *data, int x);
void			create_tex(t_data *data, int x, int y);
int				get_wall_id(t_data *data);
unsigned int	get_color(t_pic *tex, int x, int y);
void			fill_img(t_data *data);
int				key_hook(int keycode, t_data *data);
void			move_forward_and_back(t_data *data, int sign);
void			move_left_and_right(t_data *data, int sign);
void			rotate(t_data *data, int sign);
int				click_red_cross(t_data *data);

#endif