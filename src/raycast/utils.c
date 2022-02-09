/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:55:56 by mlatashi          #+#    #+#             */
/*   Updated: 2022/02/04 23:55:59 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_img(t_data *data)
{
	int		x;
	int		y;
	char	*pix;

	y = -1;
	while (++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			pix = data->img->addr + y * data->img->size_line
				+ x * (data->img->bpp / 8);
			*(unsigned int *)pix = data->screen[y][x];
			data->screen[y][x] = 0;
		}
	}
}
