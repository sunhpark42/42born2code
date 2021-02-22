/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:21:27 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/18 15:10:05 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	char				*s_ptr;
	unsigned	int		i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	s_ptr = (char*)s;
	i = 0;
	while (i < len)
	{
		*(substr + i) = *(s_ptr + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}
