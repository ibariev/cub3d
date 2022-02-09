/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_type_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2022/02/07 17:42:01 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_type_data_texture(t_info *info, char **map_type, int type_id)
{
	char	*filepath;

	filepath = map_type[1];
	if (type_id == TYPE_NO)
		info->no_texture = ft_strdup(filepath);
	if (type_id == TYPE_SO)
		info->so_texture = ft_strdup(filepath);
	if (type_id == TYPE_WE)
		info->we_texture = ft_strdup(filepath);
	if (type_id == TYPE_EA)
		info->ea_texture = ft_strdup(filepath);
}

int	get_num_of_type_data(char **s)
{
	int		count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

bool	check_num_of_type_data_fc(char **map_type)
{
	char	**tmp;
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (map_type[++i])
	{
		tmp = ft_split(map_type[i], ',');
		j = -1;
		while (tmp[++j])
			count++;
		free_double_pointer(&tmp);
	}
	if (count != 3)
		return (false);
	return (true);
}

void	get_type_data_fc(t_info *info, char **map_type)
{
	char	*type_id;
	char	**split_data;
	int		rgb;
	int		i;
	int		j;

	rgb = 0;
	type_id = map_type[0];
	i = 0;
	while (map_type[++i])
	{
		split_data = ft_split(map_type[i], ',');
		j = -1;
		while (split_data[++j])
		{
			rgb = rgb << 8;
			rgb = rgb + ft_atoi(split_data[j]);
		}
		free_double_pointer(&split_data);
	}
	if (ft_strncmp("F", type_id, 2) == 0)
		info->floor_color = rgb;
	if (ft_strncmp("C", type_id, 2) == 0)
		info->ceiling_color = rgb;
}

void	get_type_data(t_info *info, char **map_type, int type_id)
{
	if (type_id == TYPE_NO || type_id == TYPE_SO || \
		type_id == TYPE_WE || type_id == TYPE_EA)
	{
		if (get_num_of_type_data(map_type) != 2)
			error_exit("Too many type identifier data.: NO SO WA EA S");
		check_type_data_texture(map_type);
		get_type_data_texture(info, map_type, type_id);
	}
	if (type_id == TYPE_F || type_id == TYPE_C)
	{
		if (check_num_of_type_data_fc(map_type) == false)
			error_exit("Too many type identifier data.: F C");
		check_type_data_fc(map_type);
		get_type_data_fc(info, map_type);
	}
}
