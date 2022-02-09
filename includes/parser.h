/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2022/02/05 17:20:01 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define TYPE_NONE 0
# define TYPE_NO 1
# define TYPE_SO 2
# define TYPE_WE 3
# define TYPE_EA 4
# define TYPE_F 5
# define TYPE_C 6
# define TYPE_MAP 7
# define FLOOR '0'
# define WALL '1'
# define SPACE ' '
# define PLAYER '3'

typedef struct s_info
{
	double	x;
	double	y;
	char	directory;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	int		map_width;
	int		map_height;
	char	**map;
}	t_info;

void	parse_map(int argc, char **argv, t_info *info);
char	**store_file_data(char *filepath);
void	get_file_data(t_info *info, char **tmp_file_data);
void	check_type_data_texture(char **map_type);
void	check_type_data_fc(char **map_type);
void	get_type_data(t_info *info, char **map_type, int type_id);
void	get_map_data(t_info *info, char **tmp_file_data);
void	get_map(t_info *info, char **tmp_file_data);
void	print_info(t_info *info);
void	set_player(t_info *info, char map_tile, int x, int y);

void	free_double_pointer(char ***s);
void	error_exit(char *error_msg);
bool	is_type_id(char *type_id);
int		get_kind_of_type(char *type_id);

#endif