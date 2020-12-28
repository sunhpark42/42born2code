/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:43:56 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:43:58 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t				i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
