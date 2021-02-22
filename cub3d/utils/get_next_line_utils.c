/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:03:56 by sunhpark          #+#    #+#             */
/*   Updated: 2020/11/01 18:38:55 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			g_ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int			g_ft_strchr(char *str, char ch)
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

char		*g_ft_strdup(char *dst, char *src)
{
	int				i;
	char			*ret;

	i = 0;
	if (!src)
		return (0);
	ret = (char*)malloc(sizeof(char) * (g_ft_strlen(src) + 1));
	if (!ret)
		return (0);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	if (dst)
	{
		free(dst);
		dst = NULL;
	}
	return (ret);
}

char		*g_ft_strjoin(char *dst, char *src, int s_len)
{
	char			*ret;
	int				i;
	int				j;

	ret = (char*)malloc(sizeof(char) * (g_ft_strlen(dst) + s_len + 1));
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
