/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:54:07 by mlatashi          #+#    #+#             */
/*   Updated: 2022/02/05 00:08:21 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward_and_back(t_data *data, int sign)
{
	double	sp;

	sp = (double) sign * MV_SPEED;
	if (data->map[(int)(data->py + sp * data->dir_y)][(int) data->px] == '0')
		data->py += sp * data->dir_y;
	if (data->map[(int) data->py][(int)(data->px + sp * data->dir_x)] == '0')
		data->px += sp * data->dir_x;
}

void	move_left_and_right(t_data *data, int sign)
{
	double	sp;

	sp = (double) sign * MV_SPEED;
	if (data->map[(int)(data->py + sp * data->dir_x)][(int) data->px] == '0')
			data->py += sp * data->dir_x;
	if (data->map[(int) data->py][(int)(data->px - sp * data->dir_y)] == '0')
		data->px -= sp * data->dir_y;
}

void	rotate(t_data *data, int sign)
{
	double	old_dirx;
	double	old_planex;
	double	angle;

	old_dirx = data->dir_x;
	old_planex = data->plane_x;
	angle = (double) sign * PI / 12;
	data->dir_x = data->dir_x * cos(angle) + data->dir_y * sin(angle);
	data->dir_y = -old_dirx * sin(angle) + data->dir_y * cos(angle);
	data->plane_x = data->plane_x * cos(angle) + data->plane_y * sin(angle);
	data->plane_y = -old_planex * sin(angle) + data->plane_y * cos(angle);
}

int	click_red_cross(t_data *data)
{
	int	i;

	mlx_destroy_window(data->mlx, data->win);
	i = -1;
	while (++i < data->pars->map_height)
		free(data->pars->map[i]);
	free(data->pars->map);
	mlx_destroy_image(data->mlx, data->tex[0].img);
	mlx_destroy_image(data->mlx, data->tex[1].img);
	mlx_destroy_image(data->mlx, data->tex[2].img);
	mlx_destroy_image(data->mlx, data->tex[3].img);
	mlx_destroy_image(data->mlx, data->img->img);
	free(data->img);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		move_forward_and_back(data, 1);
	else if (keycode == S_KEY)
		move_forward_and_back(data, -1);
	else if (keycode == A_KEY)
		move_left_and_right(data, -1);
	else if (keycode == D_KEY)
		move_left_and_right(data, 1);
	else if (keycode == LEFT_ARROW)
		rotate(data, 1);
	else if (keycode == RIGHT_ARROW)
		rotate(data, -1);
	else if (keycode == ESC_KEY)
		click_red_cross(data);
	draw(data);
	return (0);
}
