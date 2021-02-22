/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:28:19 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/18 14:41:37 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned	char	*tmp;
	size_t				i;

	tmp = 0;
	i = 0;
	if (!dest && !src)
		return (dest);
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (i < n)
		{
			tmp = (unsigned char*)(src + n - i - 1);
			*(unsigned char*)(dest + n - i - 1) = *tmp;
			i++;
		}
	}
	return (dest);
}
