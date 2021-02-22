/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:49:45 by sunhpark          #+#    #+#             */
/*   Updated: 2020/06/30 17:40:48 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t						i;
	unsigned	char			*p_dest;
	const	unsigned	char	*p_src = src;
	unsigned	char			key;

	i = 0;
	p_dest = dest;
	key = (unsigned char)c;
	while (i < n)
	{
		*(p_dest + i) = *(p_src + i);
		if (*(p_src + i) == key)
			return (p_dest + i + 1);
		i++;
	}
	return (0);
}
