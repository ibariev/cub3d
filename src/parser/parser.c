/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2022/02/07 18:23:37 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_info(t_info *info)
{
	int		i;

	printf("### print_info ###\n");
	printf("p_pos: (%f, %f)\n", info->x, info->y);
	printf("p_direction: (%c)\n", info->directory);
	printf("no_texture: %s\n", info->no_texture);
	printf("so_texture: %s\n", info->so_texture);
	printf("we_texture: %s\n", info->we_texture);
	printf("ea_texture: %s\n", info->ea_texture);
	printf("floor_color: %d\n", info->floor_color);
	printf("ceiling_color: %d\n", info->ceiling_color);
	printf("map_width: %d\n", info->map_width);
	printf("map_height: %d\n", info->map_height);
	printf("map: \n");
	if (info->map)
	{
		i = -1;
		while (info->map[++i])
			printf("%s\n", info->map[i]);
	}
}

void	check_param(int argc, char *filepath)
{
	char	*extension;

	if (argc != 2)
		error_exit("Invalid parameters.");
	extension = ft_strrchr(filepath, '.');
	if (ft_strncmp(".cub", extension, 5) != 0)
		error_exit("It's an incorrrect extension.");
}

void	parse_map(int argc, char **argv, t_info *info)
{
	char	**tmp_file_data;

	check_param(argc, argv[1]);
	tmp_file_data = store_file_data(argv[1]);
	get_file_data(info, tmp_file_data);
	get_map(info, tmp_file_data);
	free_double_pointer(&tmp_file_data);
}
