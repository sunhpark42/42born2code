/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_temp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:54:59 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/16 15:58:55 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_numlen(int n)
{
	int			len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*ret;
	int			neg;
	int			len;

	neg = 1;
	len = ft_numlen(n);
	if (n < 0)
		neg = -neg;
	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	*(ret + len) = '\0';
	while (len > 0)
	{
		*(ret + len - 1) = (neg * (n % 10)) + '0';
		n /= 10;
		len--;
	}
	if (neg < 0)
		*ret = '-';
	return (ret);
}
