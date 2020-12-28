/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:43:16 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:43:18 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_leftalign(int width, int precision, int len, unsigned int num)
{
	ft_print_zero(precision - len);
	ft_putunsignednbr_fd(num, 1);
	if (precision > len)
		ft_print_space(width - precision);
	else
		ft_print_space(width - len);
}

void	u_zeropadding(int width, int len, unsigned int num)
{
	ft_print_zero(width - len);
	ft_putunsignednbr_fd(num, 1);
}

void	u_rigthalign(int width, int precision, int len, unsigned int num)
{
	if (precision > len)
		ft_print_space(width - precision);
	else
		ft_print_space(width - len);
	ft_print_zero(precision - len);
	ft_putunsignednbr_fd(num, 1);
}

/*
** unsigned decimal
** if precision, zero-padding is ignored.
*/

int		ft_print_unsigned_decimal(t_format *format_info, va_list *args)
{
	unsigned int	num;
	int				len;

	num = va_arg(*args, unsigned int);
	len = ft_numlen(num);
	if (format_info->precision == 0 && num == 0)
		return (ft_zero_precision_retval(format_info->width));
	if (format_info->flag == LEFTALIGN)
		u_leftalign(format_info->width, format_info->precision, len, num);
	else if (format_info->flag == ZEROPADDING && format_info->precision < 0)
		u_zeropadding(format_info->width, len, num);
	else
		u_rigthalign(format_info->width, format_info->precision, len, num);
	return (decide_retval(format_info->width, format_info->precision, len));
}
