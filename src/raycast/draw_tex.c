/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:39:18 by mlatashi          #+#    #+#             */
/*   Updated: 2022/02/04 23:39:48 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_hit(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == '1')
			data->hit = 1;
	}
}

int	get_wall_id(t_data *data)
{
	if (data->side == 1 && data->raydir_y < 0)
		return (0);
	else if (data->side == 1 && data->raydir_y > 0)
		return (1);
	else if (data->side == 0 && data->raydir_x < 0)
		return (2);
	else
		return (3);
}

unsigned int	get_color(t_pic *tex, int x, int y)
{
	return (*((unsigned *)(tex->addr + y * tex->size_line + x * tex->bpp / 8)));
}

void	create_tex(t_data *data, int x, int y)
{
	unsigned int	clr;
	int				id;

	data->tex_y = (int) data->tex_pos & (TEX_H - 1);
	data->tex_pos += data->tex_step;
	id = get_wall_id(data);
	clr = get_color(&data->tex[id], data->tex_x, data->tex_y);
	if (data->side == 0)
		clr = (clr >> 1) & 0x7F7F7F;
	data->screen[y][x] = clr;
}

void	draw_tex(t_data *data, int x)
{
	int	y;

	if (data->side == 0)
		data->wall_x = data->py + data->perp_wd * data->raydir_y;
	else
		data->wall_x = data->px + data->perp_wd * data->raydir_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = data->wall_x * TEX_W;
	if (data->side == 0 && data->raydir_x < 0)
		data->tex_x = TEX_W - data->tex_x - 1;
	if (data->side == 1 && data->raydir_y > 0)
		data->tex_x = TEX_W - data->tex_x - 1;
	data->tex_step = 1.0 * TEX_H / data->line_height;
	data->tex_pos = (data->start_draw - SCREEN_H / 2 + data->line_height / 2)
		* data->tex_step;
	y = data->start_draw - 1;
	while (++y < data->end_draw + 1)
		create_tex(data, x, y);
}
