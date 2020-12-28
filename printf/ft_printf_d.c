/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:42:21 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:42:26 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero_precision_retval(int width)
{
	ft_print_space(width);
	if (width < 0)
		return (0);
	return (width);
}

void	d_leftalign(t_format *f_info, int negative, int len, int num)
{
	if (negative < 0)
		ft_putchar_fd('-', 1);
	ft_print_zero(f_info->precision - len);
	ft_putunsignednbr_fd(negative * num, 1);
	ft_print_precision(f_info->width, f_info->precision, len);
}

void	d_rightalign(t_format *f_info, int negative, int len, int num)
{
	ft_print_precision(f_info->width, f_info->precision, len);
	if (negative < 0)
		ft_putchar_fd('-', 1);
	ft_print_zero(f_info->precision - len);
	ft_putunsignednbr_fd(negative * num, 1);
}

void	d_zeropadding(int width, int negative, int len, int num)
{
	if (negative < 0)
		ft_putchar_fd('-', 1);
	ft_print_zero(width - len);
	ft_putunsignednbr_fd(negative * num, 1);
}

/*
** decimal
** if precision, zero-padding is ignored.
*/

int		ft_print_decimal(t_format *f_info, va_list *args)
{
	int				num;
	int				len;
	int				negative;

	num = va_arg(*args, int);
	negative = 1;
	len = 0;
	if (num < 0)
	{
		negative = -1;
		len++;
		f_info->precision++;
	}
	len += ft_numlen(negative * num);
	if (f_info->precision == 0 && num == 0)
		return (ft_zero_precision_retval(f_info->width));
	if (f_info->flag == LEFTALIGN)
		d_leftalign(f_info, negative, len, num);
	else if (f_info->flag == ZEROPADDING && f_info->precision < 0)
		d_zeropadding(f_info->width, negative, len, num);
	else
		d_rightalign(f_info, negative, len, num);
	if (f_info->precision - len > 0)
		len += (f_info->precision - len);
	return (decide_retval(f_info->width, 0, len));
}
