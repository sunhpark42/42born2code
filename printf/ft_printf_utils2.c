/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:43:38 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:43:39 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexa_numlen(unsigned long long num)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_decimal_to_hexa(unsigned long long num)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_hexa_numlen(num);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		if (num % 16 < 10)
			str[len - i - 1] = num % 16 + '0';
		else
			str[len - i - 1] = num % 16 + 'a' - 10;
		num /= 16;
		i++;
	}
	str[len] = '\0';
	return (str);
}

int		decide_retval(int width, int precision, int len)
{
	if (width > len && width >= precision)
		return (width);
	else if (precision > len)
		return (precision);
	else
		return (len);
}

void	ft_print_precision(int width, int precision, int len)
{
	if (precision > len)
		ft_print_space(width - precision);
	else
		ft_print_space(width - len);
}
