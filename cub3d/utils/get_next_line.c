/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 23:50:30 by sunhpark          #+#    #+#             */
/*   Updated: 2020/11/01 20:20:24 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			iserr(int fd, char **line)
{
	if (!line)
		return (1);
	if (fd < 0 || fd > 65535)
		return (1);
	if (BUFFER_SIZE <= 0)
		return (1);
	return (0);
}

int			get_temp(int fd, char **line, char **temp)
{
	int				ptr;

	if ((ptr = g_ft_strchr(temp[fd], '\n')) > -1)
	{
		*line = g_ft_strjoin(*line, temp[fd], ptr);
		temp[fd] = g_ft_strdup(temp[fd], temp[fd] + ptr + 1);
		return (1);
	}
	*line = g_ft_strdup(*line, temp[fd]);
	if (temp[fd])
	{
		free(temp[fd]);
		temp[fd] = NULL;
	}
	return (0);
}

void		free_buf(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
}

int			get_line(int fd, char **line, char **temp)
{
	int				rd;
	char			*buf;
	int				ptr;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((rd = read(fd, buf, BUFFER_SIZE)))
	{
		if (rd == -1)
		{
			free_buf(buf);
			return (-1);
		}
		buf[rd] = '\0';
		if ((ptr = g_ft_strchr(buf, '\n')) > -1)
		{
			*line = g_ft_strjoin(*line, buf, ptr);
			temp[fd] = g_ft_strdup(temp[fd], buf + ptr + 1);
			free_buf(buf);
			return (1);
		}
		*line = g_ft_strjoin(*line, buf, rd);
	}
	free_buf(buf);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static	char	*temp[1024];
	int				ret;

	if (iserr(fd, line))
		return (-1);
	*line = NULL;
	if (temp[fd])
		if (get_temp(fd, line, temp))
			return (1);
	ret = get_line(fd, line, temp);
	if (ret == 1)
		return (1);
	if (ret == -1)
		return (-1);
	*line = g_ft_strjoin(*line, "", 1);
	if (temp[fd])
		free_buf(temp[fd]);
	return (0);
}
