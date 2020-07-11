/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:03:39 by sunhpark          #+#    #+#             */
/*   Updated: 2020/06/30 17:54:00 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned	char	*p;
	unsigned	char	ch;
	size_t				i;

	i = 0;
	p = s;
	ch = (unsigned char)c;
	while (i < n)
	{
		*p = ch;
		p++;
		i++;
	}
	return (s);
}
