/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:59:51 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/02 20:03:33 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned	char	*p_s1;
	unsigned	char	*p_s2;

	i = 0;
	p_s1 = (unsigned char*)s1;
	p_s2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*p_s1 && *p_s2 && i < n - 1)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		p_s1++;
		p_s2++;
		i++;
	}
	return (*p_s1 - *p_s2);
}
