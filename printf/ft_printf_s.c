/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:42:54 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:42:56 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(*(str + i), 1);
		i++;
	}
}

/*
** str
** flag '0' : undefinde behavior
*/

int		ft_print_str(t_format *format_info, va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (format_info->precision < len && format_info->precision > 0)
		len = format_info->precision;
	if (format_info->precision == 0)
		return (ft_zero_precision_retval(format_info->width));
	if (format_info->flag == LEFTALIGN)
	{
		ft_putnstr(str, len);
		ft_print_space(format_info->width - len);
	}
	else
	{
		ft_print_space(format_info->width - len);
		ft_putnstr(str, len);
	}
	return (decide_retval(format_info->width, 0, len));
}
