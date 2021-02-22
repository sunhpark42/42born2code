/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:53:57 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/18 14:55:05 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			n_len;
	size_t			h_len;

	n_len = ft_strlen(needle);
	h_len = ft_strlen(haystack);
	i = 0;
	if (len == 0 && n_len == 0)
		return ((char*)haystack);
	while (i < len)
	{
		if (!ft_strncmp((haystack + i), needle, n_len) && len - i >= n_len)
			return ((char*)(haystack + i));
		i++;
	}
	return (0);
}
