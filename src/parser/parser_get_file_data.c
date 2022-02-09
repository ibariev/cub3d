/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_file_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2022/02/07 17:42:05 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_num_of_type_id(char **tmp_file_data)
{
	char	**split;
	int		type_count;
	int		i;

	type_count = 0;
	i = -1;
	while (tmp_file_data[++i])
	{
		split = ft_split(tmp_file_data[i], ' ');
		if (split[0] && get_kind_of_type(split[0]) != TYPE_MAP
			&& get_kind_of_type(split[0]) != TYPE_NONE)
			type_count++;
		free_double_pointer(&split);
	}	
	if (type_count != 6)
		error_exit("There are too many or too few types.");
}

void	check_file_data(t_info *info)
{
	if (info->no_texture == NULL)
		error_exit("The north texture file does not exist.");
	if (info->so_texture == NULL)
		error_exit("The south texture file does not exist.");
	if (info->we_texture == NULL)
		error_exit("The west texture file does not exist.");
	if (info->ea_texture == NULL)
		error_exit("The east texture file does not exist.");
	if (info->floor_color == 0)
		error_exit("Invalid floor rgb value.");
	if (info->ceiling_color == 0)
		error_exit("Invalid ceiling rgb value.");
	if (info->map_width == 0)
		error_exit("Invalid map size.");
	if (info->map_height == 0)
		error_exit("Invalid map size.");
}

/* TODO: info안에 유형 식별자값이 0인 경우 예외처리
	- get_type_data 후, info안에 값들이 전부 있는지 확인 */
/* TODO: обработка исключений, когда значение идентификатора типа в
 * информации равно 0
- После get_type_data проверить, все ли значения в инфо */
void	get_file_data(t_info *info, char **tmp_file_data)
{
	char	**type_line;
	int		i;

	check_num_of_type_id(tmp_file_data);
	i = -1;
	while (tmp_file_data[++i])
	{
		if (tmp_file_data[i][0] == '\0')
			continue ;
		type_line = ft_split(tmp_file_data[i], ' ');
		if (is_type_id(type_line[0]) == false)
			error_exit("Invalid type identifier.");
		get_type_data(info, type_line, get_kind_of_type(type_line[0]));
		free_double_pointer(&type_line);
	}
	get_map_data(info, tmp_file_data);
	check_file_data(info);
}
