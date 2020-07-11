/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:25:27 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/06 21:59:04 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*ret_str;
	size_t				len;
	size_t				i;
	size_t				j;

	len = ft_strlen(s1) + ft_strlen(s2);
	ret_str = (char*)malloc(sizeof(len + 1));
	if (!ret_str)
		return (0);
	i = 0;
	j = 0;
	while (*(s1 + i))
	{
		*(ret_str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(ret_str + i) = *(s2 + j);
		j++;
		i++;
	}
	*(ret_str + i) = 0;
	return (ret_str);
}
