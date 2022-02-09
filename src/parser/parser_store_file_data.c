/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_store_file_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlatashi <mlatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2022/02/07 17:41:58 by mlatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_len_of_line(char *filepath)
{
	int		len;
	char	*line;
	int		fd;

	len = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		error_exit("File does not exist.");
	while (get_next_line(fd, &line) > 0)
	{
		len++;
		free(line);
	}
	len++;
	free(line);
	close(fd);
	return (len);
}

char	**store_file_data(char *filepath)
{
	char	**tmp_file_data;
	int		fd;
	char	*line;
	int		i;
	int		len_of_line;

	len_of_line = get_len_of_line(filepath);
	tmp_file_data = (char **)ft_calloc(len_of_line + 1, sizeof(char *));
	if (!tmp_file_data)
		error_exit("Malloc allocation failed.");
	fd = open(filepath, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		tmp_file_data[i++] = line;
	}
	tmp_file_data[i++] = line;
	tmp_file_data[i++] = NULL;
	close(fd);
	return (tmp_file_data);
}
