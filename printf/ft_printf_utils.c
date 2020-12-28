/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:43:26 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:43:28 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_create_format_info(void)
{
	t_format		*format_info;

	format_info = (t_format*)malloc(sizeof(t_format));
	if (!format_info)
		return (0);
	format_info->len = 0;
	format_info->flag = 0;
	format_info->width = -1;
	format_info->precision = -2;
	format_info->conversion = '\0';
	return (format_info);
}

void		ft_print_space(int count)
{
	int				i;

	i = 0;
	while (i < count)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

void		ft_print_zero(int count)
{
	int				i;

	i = 0;
	while (i < count)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
}

int			ft_numlen(unsigned int num)
{
	int				len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void		ft_putunsignednbr_fd(unsigned int n, int fd)
{
	if (fd < 0)
		return ;
	if (n >= 0)
	{
		if (n >= 10)
			ft_putunsignednbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
