/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:44:22 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:44:24 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print pointer
** flag '0' : undefined function
** precision : undefined function
*/

int		ft_print_pointer(t_format *format_info, va_list *args)
{
	unsigned long long	ptr;
	char				*address;
	int					len;

	ptr = (unsigned long long)va_arg(*args, void*);
	address = ft_decimal_to_hexa(ptr);
	len = ft_strlen(address) + 2;
	if (format_info->precision == 0 && !ptr)
		len--;
	if (format_info->flag == LEFTALIGN)
	{
		ft_putstr_fd("0x", 1);
		if (format_info->precision < 0 || ptr != 0)
			ft_putstr_fd(address, 1);
		ft_print_space(format_info->width - len);
	}
	else
	{
		ft_print_space(format_info->width - len);
		ft_putstr_fd("0x", 1);
		if (format_info->precision < 0 || ptr != 0)
			ft_putstr_fd(address, 1);
	}
	free(address);
	return (decide_retval(format_info->width, 0, len));
}
