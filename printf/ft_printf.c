/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:40:57 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:41:43 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putarg(t_format *format_info, va_list *args)
{
	int					len;

	len = 0;
	if (format_info->conversion == 'c')
		len = ft_print_char(format_info, args);
	if (format_info->conversion == 's')
		len = ft_print_str(format_info, args);
	if (format_info->conversion == 'p')
		len = ft_print_pointer(format_info, args);
	if (format_info->conversion == 'd')
		len = ft_print_decimal(format_info, args);
	if (format_info->conversion == 'i')
		len = ft_print_decimal(format_info, args);
	if (format_info->conversion == 'u')
		len = ft_print_unsigned_decimal(format_info, args);
	if (format_info->conversion == 'x')
		len = ft_print_hexa(format_info, args, "lower");
	if (format_info->conversion == 'X')
		len = ft_print_hexa(format_info, args, "upper");
	if (format_info->conversion == '%')
		len = ft_print_percent(format_info);
	return (len);
}

int			ft_print_main(const char *format, va_list *args, int len)
{
	t_format		*format_info;
	int				i;
	int				total;

	i = 0;
	total = 0;
	while (i < len)
	{
		if (!(format_info = ft_create_format_info()))
			return (0);
		if (*(format + i) == '%')
		{
			format_info = format_parser(format + i + 1, format_info, args);
			i += format_info->len;
			total += ft_putarg(format_info, args);
		}
		else
		{
			ft_putchar_fd(*(format + i), 1);
			total++;
		}
		free(format_info);
		i++;
	}
	return (total);
}

/*
** main function
*/

int			ft_printf(const char *format, ...)
{
	va_list			args;
	int				len;
	int				total;

	va_start(args, format);
	len = ft_strlen(format);
	total = ft_print_main(format, &args, len);
	va_end(args);
	return (total);
}
