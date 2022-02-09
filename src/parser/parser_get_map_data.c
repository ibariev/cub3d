/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_map_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2022/02/07 17:42:03 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_map_data(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ' || \
			line[i] == 'N' || line[i] == 'E' || line[i] == 'W' || \
			line[i] == 'S')
			continue ;
		error_exit("Map file is not valid.");
	}
}

void	get_map_data(t_info *info, char **tmp_file_data)
{
	char	*line;
	int		i;

	info->map_height = 0;
	info->map_width = 0;
	i = -1;
	while (tmp_file_data[++i])
	{
		line = tmp_file_data[i];
		if (ft_atoi(line) == 0)
			continue ;
		check_map_data(line);
		if (*line == '\0' || (*line == ' ' && ft_atoi(line) == 0))
			continue ;
		if (info->map_width < (int)ft_strlen(line))
			info->map_width = (int)ft_strlen(line);
		info->map_height++;
	}
}
