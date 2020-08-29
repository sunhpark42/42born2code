/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:25:27 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/18 15:54:11 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*ret_str;
	size_t				i;
	size_t				j;

	if (!s1 || !s2)
		return (0);
	ret_str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
