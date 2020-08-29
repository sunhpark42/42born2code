/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:36:23 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/18 15:23:13 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_charset(char c, char const *set)
{
	if (ft_strchr(set, c) != 0)
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t			start;
	size_t			end;
	char			*ret;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (is_charset(*(s1 + start), set) && (*(s1 + start)))
		start++;
	while (is_charset(*(s1 + end - 1), set) && end > 1)
		end--;
	if (start > end)
		return (ft_strdup(""));
	else
	{
		ret = (char*)malloc(sizeof(char) * (end - start + 1));
		if (!ret)
			return (0);
		ft_strlcpy(ret, s1 + start, end - start + 1);
	}
	return (ret);
}
