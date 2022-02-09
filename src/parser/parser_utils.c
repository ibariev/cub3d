/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2022/02/05 17:20:37 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error_exit(char *error_msg)
{
	ft_putstr_fd("Error Message: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

bool	is_type_id(char *type_id)
{
	if (type_id && ft_strncmp("NO", type_id, 3) == 0)
		return (true);
	if (type_id && ft_strncmp("SO", type_id, 3) == 0)
		return (true);
	if (type_id && ft_strncmp("WE", type_id, 3) == 0)
		return (true);
	if (type_id && ft_strncmp("EA", type_id, 3) == 0)
		return (true);
	if (type_id && ft_strncmp("F", type_id, 2) == 0)
		return (true);
	if (type_id && ft_strncmp("C", type_id, 2) == 0)
		return (true);
	if (type_id && ft_strncmp("1", type_id, 1) == 0)
		return (true);
	if (type_id && ft_strncmp(" ", type_id, 1) == 0)
		return (true);
	if (type_id && ft_strncmp("0", type_id, 1) == 0)
		return (true);
	return (false);
}

int	get_kind_of_type(char *type_id)
{
	if (ft_strncmp("NO", type_id, 3) == 0)
		return (TYPE_NO);
	if (ft_strncmp("SO", type_id, 3) == 0)
		return (TYPE_SO);
	if (ft_strncmp("WE", type_id, 3) == 0)
		return (TYPE_WE);
	if (ft_strncmp("EA", type_id, 3) == 0)
		return (TYPE_EA);
	if (ft_strncmp("F", type_id, 2) == 0)
		return (TYPE_F);
	if (ft_strncmp("C", type_id, 2) == 0)
		return (TYPE_C);
	if (ft_strncmp("1", type_id, 1) == 0)
		return (TYPE_MAP);
	if (ft_strncmp(" ", type_id, 1) == 0)
		return (TYPE_MAP);
	if (ft_strncmp("0", type_id, 1) == 0)
		return (TYPE_MAP);
	return (TYPE_NONE);
}

void	set_player(t_info *info, char map_tile, int x, int y)
{
	info->x = x;
	info->y = y;
	info->map[y][x] = FLOOR;
	info->directory = map_tile;
}

void	free_double_pointer(char ***s)
{
	int		i;

	i = -1;
	while ((*s)[++i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
	}
	free(*s);
	*s = NULL;
}
