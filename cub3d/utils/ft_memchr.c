/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:12:14 by sunhpark          #+#    #+#             */
/*   Updated: 2020/06/30 17:52:34 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned	char	key;

	key = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s + i) == key)
			return ((unsigned char*)(s + i));
		i++;
	}
	return (0);
}
