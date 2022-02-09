/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2022/02/07 17:22:04 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_closed_map(t_info *info, int x, int y)
{
	if (y == 0 || x == 0)
		return (false);
	if (info->map[y][x - 1] == SPACE || info->map[y][x - 1] == '\0')
		return (false);
	if (info->map[y - 1][x] == SPACE || info->map[y - 1][x] == '\0')
		return (false);
	if (info->map[y][x + 1] == SPACE || info->map[y][x + 1] == '\0')
		return (false);
	if ((y + 1) == info->map_height)
		return (false);
	if (info->map[y + 1][x] == SPACE || info->map[y + 1][x] == '\0')
		return (false);
	return (true);
}

bool	player(t_info *info)
{
	char	map_tile;
	int		x;
	int		y;
	bool	has_player;

	has_player = false;
	y = -1;
	while (info->map[++y])
	{
		x = -1;
		while (info->map[y][++x])
		{
			map_tile = info->map[y][x];
			if (map_tile == 'N' || map_tile == 'S' || \
				map_tile == 'W' || map_tile == 'E')
			{
				if (has_player == true)
					error_exit("Players can't be more than one");
				set_player(info, map_tile, x, y);
				has_player = true;
			}
		}
	}
	return (has_player);
}

bool	read_map(t_info *info)
{
	char	map_tile;
	int		x;
	int		y;
	bool	has_player;

	has_player = player(info);
	y = -1;
	while (info->map[++y])
	{
		x = -1;
		while (info->map[y][++x])
		{
			map_tile = info->map[y][x];
			if (map_tile == FLOOR)
				if (check_closed_map(info, x, y) == false)
					error_exit("The map is not closed.");
		}
	}
	return (has_player);
}

int	get_map_index(char **tmp_file_data)
{
	int	i;

	i = 0;
	while (tmp_file_data[i])
	{
		if (ft_atoi(tmp_file_data[i]) == 0)
			i++;
		else if (*(tmp_file_data[i]) == '\0' || (*(tmp_file_data[i]) == ' '
				&& ft_atoi(tmp_file_data[i]) == 0))
			i++;
		else
			break ;
	}
	return (i);
}

void	get_map(t_info *info, char **tmp_file_data)
{
	char	**map;
	char	*line;
	int		m_i;
	int		i;

	m_i = 0;
	map = (char **)ft_calloc(info->map_height + 1, sizeof(char *));
	if (!map)
		error_exit("Malloc allocation failed.");
	i = 6;
	while (tmp_file_data[i] && m_i < info->map_height)
	{
		line = tmp_file_data[i];
		map[m_i++] = ft_strdup(line);
		i++;
	}
	info->map = map;
	if (read_map(info) == false)
		error_exit("Invalid map\n");
}
