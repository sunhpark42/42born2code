/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:30:37 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/02 21:42:31 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t				i;
	void				*ret;

	i = 0;
	ret = malloc(sizeof(size) * count);
	if (!ret)
		return (0);
	while (i < count)
	{
		*(char*)(ret + i) = 0;
		i++;
	}
	return (ret);
}
