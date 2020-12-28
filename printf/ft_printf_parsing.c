/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:42:35 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:42:37 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** parsing by order %[flags][width][.precision][length]specifier
** flag 0 is ignored by '-'
*/

int			ft_flag(const char *format, t_format *f_info)
{
	int			i;

	i = 0;
	while (*(format + i) == '0' || *(format + i) == '-')
	{
		if (f_info->flag == 0 && *(format + i) == '0')
			f_info->flag = ZEROPADDING;
		if (*(format + i) == '-')
			f_info->flag = LEFTALIGN;
		i++;
	}
	return (i);
}

int			ft_width(const char *format, t_format *f_info, va_list *args)
{
	int			i;

	i = 0;
	while (ft_isdigit(*(format + i)))
	{
		if (f_info->width == -1)
			f_info->width = 0;
		f_info->width *= 10;
		f_info->width = f_info->width + *(format + i) - '0';
		i++;
	}
	if (*(format + i) == '*')
	{
		f_info->width = va_arg(*args, int);
		if (f_info->width < 0)
		{
			f_info->flag = LEFTALIGN;
			f_info->width *= -1;
		}
		i++;
	}
	return (i);
}

int			ft_precision(const char *format, t_format *f_info, va_list *args)
{
	int			i;

	i = 0;
	if (*(format + i) != '.')
		return (i);
	else
	{
		i++;
		f_info->precision = 0;
	}
	while (ft_isdigit(*(format + i)))
	{
		f_info->precision *= 10;
		f_info->precision = f_info->precision + *(format + i) - '0';
		i++;
	}
	if (*(format + i) == '*')
	{
		f_info->precision = va_arg(*args, int);
		if (f_info->precision < 0)
			f_info->precision = -2;
		i++;
	}
	return (i);
}

int			ft_conversion(const char *format, t_format *f_info)
{
	int			i;

	i = 0;
	if (*(format + i) == 'c' || *(format + i) == 's' || *(format + i) == 'p'
		|| *(format + i) == 'd' || *(format + i) == 'i' || *(format + i) == 'u'
		|| *(format + i) == 'x' || *(format + i) == 'X' || *(format + i) == '%')
	{
		f_info->conversion = *(format + i);
		i++;
	}
	return (i);
}

t_format	*format_parser(const char *format, t_format *f_info, va_list *args)
{
	int			i;

	i = 0;
	i += ft_flag(format + i, f_info);
	i += ft_width(format + i, f_info, args);
	i += ft_precision(format + i, f_info, args);
	i += ft_conversion(format + i, f_info);
	f_info->len = i;
	return (f_info);
}
