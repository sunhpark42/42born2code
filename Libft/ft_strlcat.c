/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:12:43 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/02 20:44:30 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t					i;
	size_t					j;

	i = 0;
	j = ft_strlen(dst);
	if (size <= j)
		return (size + ft_strlen(src));
	while (*(src + i) && i < size - j - 1)
	{
		*(dst + j + i) = *(src + i);
		i++;
	}
	*(dst + j + i) = '\0';
	return (j + ft_strlen(src));
}
