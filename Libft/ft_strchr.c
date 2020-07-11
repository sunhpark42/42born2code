/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:16:02 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/02 20:22:48 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;

	s_ptr = (char*)s;
	if (c == 0)
		return (s_ptr + ft_strlen(s_ptr));
	while (*s_ptr)
	{
		if (*s_ptr == c)
			return (s_ptr);
		s_ptr++;
	}
	return (0);
}
