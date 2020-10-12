/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 23:50:30 by sunhpark          #+#    #+#             */
/*   Updated: 2020/10/13 03:15:24 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int			ft_strchr(char *str, char ch)
{
	int				i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_strdup(char *dst, char *src)
{
	int				i;
	char			*ret;

	i = 0;
	if (!src)
		return (0);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret)
		return (0);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	if (dst)
		free(dst);
	return (ret);
}

char		*ft_strjoin(char *dst, char *src, int s_len)
{
	char			*ret;
	int				i;
	int				j;

	ret = (char*)malloc(sizeof(char) * (ft_strlen(dst) + s_len + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (dst && dst[i])
	{
		ret[i] = dst[i];
		i++;
	}
	while (src && src[j] && j < s_len)
	{
		ret[i] = src[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	if (dst)
		free(dst);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	int				rd;
	int				ptr;
	static	char	*temp[1024];
	char			*buf;

	if (!line)
		return (-1);
	if (fd < 0)
		return (-1);
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (fd > 65535)
		return (-1);
	*line = NULL;
	if (temp[fd])
	{
		if ((ptr = ft_strchr(temp[fd], '\n')) > -1)
		{
			*line = ft_strjoin(*line, temp[fd], ptr);
			temp[fd] = ft_strdup(temp[fd], temp[fd] + ptr + 1);
			return (1);
		}
		*line = ft_strdup(*line, temp[fd]);
		if (temp[fd])
		{
			free(temp[fd]);
			temp[fd] = NULL;
		}
	}
	while ((rd = read(fd, buf, BUFFER_SIZE)))
	{
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
		if ((ptr = ft_strchr(buf, '\n')) > -1)
		{
			*line = ft_strjoin(*line, buf, ptr);
			temp[fd] = ft_strdup(temp[fd], buf + ptr + 1);
			return (1);
		}
		*line = ft_strjoin(*line, buf, rd);
		buf[0] = '\0';
	}
	*line = ft_strjoin(*line, "", 1);
	return (0);
}
