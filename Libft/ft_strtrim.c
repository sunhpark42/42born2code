/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:36:23 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/08 20:20:33 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_charset(char	c, char const *set)
{
	if(ft_strchr(set, c) != 0)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t					start;
	size_t					end;
	size_t					len;
	size_t					i;
	char					*ret;
	
	if(!s1)
		return (0);
	len = ft_strlen(s1);
	start = 0;
	end = len;
	while (is_charset(*(s1 + start), set) && start < len)
	{
		start++;
	}
	while (is_charset(*(s1 + end - 1), set) && end > 0)
	{
		end--;
	}
	if (start <= end)
	{
		ret = (char*)malloc(sizeof(end - start + 1));
		if (!ret)
			return (0);
		i = 0;
		while (i <= end - start)
		{
			*(ret + i) = *(s1 + i + start);
			i++;
		}
		*(ret + i) = 0;
		return (ret);
	}
	else
		return (0);
}
