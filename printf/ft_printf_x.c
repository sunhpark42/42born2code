/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:43:47 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:43:50 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_leftalign(int width, int precision, int len, char *hexa)
{
	ft_print_zero(precision - len);
	ft_putstr_fd(hexa, 1);
	if (precision > len)
		ft_print_space(width - precision);
	else
		ft_print_space(width - len);
}

void	x_zeropadding(int width, int len, char *hexa)
{
	ft_print_zero(width - len);
	ft_putstr_fd(hexa, 1);
}

void	x_rightalign(int width, int precision, int len, char *hexa)
{
	if (precision > len)
		ft_print_space(width - precision);
	else
		ft_print_space(width - len);
	ft_print_zero(precision - len);
	ft_putstr_fd(hexa, 1);
}

char	*ft_str_toupper(char *str, int len)
{
	int				i;

	i = 0;
	while (i < len)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

/*
** unsigned hexadecimal
** if precision, zero-padding is ignored.
*/

int		ft_print_hexa(t_format *format_info, va_list *args, char *option)
{
	unsigned int	num;
	char			*hexa;
	int				len;
	int				i;

	num = va_arg(*args, unsigned int);
	hexa = ft_decimal_to_hexa(num);
	len = ft_strlen(hexa);
	i = 0;
	if (ft_strncmp(option, "upper", 5) == 0)
		hexa = ft_str_toupper(hexa, len);
	if (format_info->precision == 0 && num == 0)
		return (ft_zero_precision_retval(format_info->width));
	if (format_info->flag == LEFTALIGN)
		x_leftalign(format_info->width, format_info->precision, len, hexa);
	else if (format_info->flag == ZEROPADDING && format_info->precision < 0)
		x_zeropadding(format_info->width, len, hexa);
	else
		x_rightalign(format_info->width, format_info->precision, len, hexa);
	free(hexa);
	return (decide_retval(format_info->width, format_info->precision, len));
}
