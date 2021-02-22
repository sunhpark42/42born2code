/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_temp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:42:40 by sunhpark          #+#    #+#             */
/*   Updated: 2020/08/29 19:44:23 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		word_cnt(char const *s, char c)
{
	int			i;
	int			cnt;
	int			flag;

	i = 0;
	cnt = 0;
	flag = 1;
	while (*(s + i))
	{
		if (*(s + i) == c)
			flag = 1;
		else if (*(s + i) != c && flag == 1)
		{
			cnt++;
			flag = 0;
		}
		i++;
	}
	return (cnt);
}

int		word_len(char const *s, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (*(s + i) && *(s + i) != c)
	{
		len++;
		i++;
	}
	return (len);
}

void	free_ret(char **ret, int idx)
{
	int			i;

	i = 0;
	while (i < idx)
	{
		free(ret + i);
		i++;
	}
	free(ret);
}

char	**put_words(char **ret, int ret_len, char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < ret_len)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(ret + i) = (char*)malloc(sizeof(char) * (word_len(s + j, c) + 1));
		if (!(*(ret + i)))
		{
			free_ret(ret, i);
			return (0);
		}
		ft_strlcpy(*(ret + i), s + j, word_len(s + j, c) + 1);
		j += word_len(s + j, c);
		i++;
	}
	*(ret + i) = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char **ret;

	if (!s)
		return (0);
	ret = (char**)malloc(sizeof(char*) * (word_cnt(s, c) + 1));
	if (!ret)
		return (0);
	ret = put_words(ret, word_cnt(s, c), s, c);
	if (!ret)
		return (0);
	return (ret);
}
