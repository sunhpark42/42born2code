/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:16:02 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/02 20:17:53 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char				*s_ptr;
	int					i;

	s_ptr = (char*)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(s_ptr + i) == c)
			return (s_ptr + i);
		i--;
	}
	return (0);
}
