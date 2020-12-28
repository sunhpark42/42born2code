/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:42:46 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:42:48 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_percent(t_format *format_info)
{
	if (format_info->flag == LEFTALIGN)
	{
		ft_putchar_fd('%', 1);
		ft_print_space(format_info->width - 1);
	}
	else if (format_info->flag == ZEROPADDING)
	{
		ft_print_zero(format_info->width - 1);
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_print_space(format_info->width - 1);
		ft_putchar_fd('%', 1);
	}
	return (decide_retval(format_info->width, 0, 1));
}
