/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urichese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:53:22 by urichese          #+#    #+#             */
/*   Updated: 2021/04/22 19:53:25 by urichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define ERROR -1
# define SUCCESS 1
# define SUCCESS_EOF 0

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
void	update_store_buff(char ***s, size_t n);
char	*get_line(char **s);

size_t	gnl_strlen(char *s);
char	*gnl_strjoin(char *s1, char *s2);
size_t	ft_isnewline(char *s);
char	*gnl_strdup(char *s);
void	*ft_calloc(size_t count, size_t size);

#endif
