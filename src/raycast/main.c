/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:58:31 by mlatashi          #+#    #+#             */
/*   Updated: 2022/02/05 00:02:39 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;

	parse_map(argc, argv, &info);
	data.pars = &info;
	init_all(&data);
	draw(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, click_red_cross, &data);
	mlx_loop(data.mlx);
}
