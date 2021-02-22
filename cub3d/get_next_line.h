/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 03:15:54 by sunhpark          #+#    #+#             */
/*   Updated: 2020/10/14 19:25:35 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int			get_next_line(int fd, char **line);

int			g_ft_strlen(char *str);
int			g_ft_strchr(char *str, char ch);
char		*g_ft_strdup(char *dst, char *src);
char		*g_ft_strjoin(char *dst, char *src, int s_len);

#endif
