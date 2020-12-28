/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:42:12 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:42:14 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** char
** flag '0' : undefined behavior
** precision : undefined behavior
*/

int		ft_print_char(t_format *format_info, va_list *args)
{
	char			ch;

	ch = va_arg(*args, int);
	if (format_info->flag == LEFTALIGN)
	{
		ft_putchar_fd(ch, 1);
		ft_print_space(format_info->width - 1);
	}
	else
	{
		ft_print_space(format_info->width - 1);
		ft_putchar_fd(ch, 1);
	}
	return (decide_retval(format_info->width, 0, 1));
}
