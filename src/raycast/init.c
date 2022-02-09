/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:08:34 by mlatashi          #+#    #+#             */
/*   Updated: 2022/02/05 19:07:34 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_orientation(t_data *data)
{
	int	sign;

	if (data->pars->directory == 'N' || data->pars->directory == 'S')
	{
		if (data->pars->directory == 'N')
			sign = 1;
		else
			sign = -1;
		data->dir_x = 0;
		data->dir_y = -1 * sign;
		data->plane_x = 0.66 * sign;
		data->plane_y = 0;
	}
	else if (data->pars->directory == 'W' || data->pars->directory == 'E')
	{
		if (data->pars->directory == 'W')
			sign = 1;
		else
			sign = -1;
		data->dir_x = -1 * sign;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66 * sign;
	}
}

void	init_player(t_data *data)
{	
	data->px = data->pars->x + 0.3;
	data->py = data->pars->y + 0.3;
	init_orientation(data);
	data->map = data->pars->map;
}

void	init_all(t_data *data)
{
	t_pic	*screen;
	int		i;

	init_player(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "cub3D");
	screen = malloc(sizeof(*screen));
	if (screen == NULL)
		error_exit("Malloc allocation failed.");
	screen->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bpp,
			&screen->size_line, &screen->en);
	data->img = screen;
	data->tex[0].img = mlx_xpm_file_to_image(data->mlx, data->pars->no_texture,
			&data->tex[0].width, &data->tex[0].hight);
	data->tex[1].img = mlx_xpm_file_to_image(data->mlx, data->pars->so_texture,
			&data->tex[1].width, &data->tex[1].hight);
	data->tex[2].img = mlx_xpm_file_to_image(data->mlx, data->pars->we_texture,
			&data->tex[2].width, &data->tex[2].hight);
	data->tex[3].img = mlx_xpm_file_to_image(data->mlx, data->pars->ea_texture,
			&data->tex[3].width, &data->tex[3].hight);
	i = -1;
	while (++i < 4)
		data->tex[i].addr = mlx_get_data_addr(data->tex[i].img,
				&data->tex[i].bpp, &data->tex[i].size_line, &data->tex[i].en);
}
