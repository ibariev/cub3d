/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:24:34 by mlatashi          #+#    #+#             */
/*   Updated: 2022/02/04 23:33:30 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ceiling_and_floor(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SCREEN_H / 2)
	{
		x = -1;
		while (++x < SCREEN_W)
			data->screen[y][x] = data->pars->ceiling_color;
	}
	while (++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
			data->screen[y][x] = data->pars->floor_color;
	}
}

void	calc_wall_dist(t_data *data)
{
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->py - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y - data->py + 1) * data->delta_dist_y;
	}
	find_hit(data);
	if (data->side)
		data->perp_wd = data->side_dist_y - data->delta_dist_y;
	else
		data->perp_wd = data->side_dist_x - data->delta_dist_x;
	data->line_height = SCREEN_H / data->perp_wd;
	data->start_draw = SCREEN_H / 2 - data->line_height / 2;
	if (data->start_draw < 0)
		data->start_draw = 0;
	data->end_draw = SCREEN_H / 2 + data->line_height / 2;
	if (data->end_draw >= SCREEN_H)
		data->end_draw = SCREEN_H - 1;
}

void	calc_raydir(t_data *data, int x)
{
	data->camera_x = 2 * x / (double) SCREEN_W - 1;
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = data->px;
	data->map_y = data->py;
	if (data->raydir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->raydir_x);
	if (data->raydir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->raydir_y);
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->px - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x - data->px + 1) * data->delta_dist_x;
	}
	data->hit = 0;
}

void	raycast(t_data *data)
{
	int	x;

	x = -1;
	while (++x < SCREEN_W)
	{
		calc_raydir(data, x);
		calc_wall_dist(data);
		draw_tex(data, x);
	}
}

void	draw(t_data *data)
{
	draw_ceiling_and_floor(data);
	raycast(data);
	fill_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
