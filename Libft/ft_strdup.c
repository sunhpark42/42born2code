/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:23:42 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/02 21:52:50 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*ret;

	ret = (char*)malloc(sizeof(ft_strlen(s1) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	*(ret + i) = '\0';
	return (ret);
}
