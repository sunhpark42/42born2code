/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <sunhpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:41:23 by sunhpark          #+#    #+#             */
/*   Updated: 2020/12/27 21:41:52 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define LEFTALIGN 2
# define ZEROPADDING 1

typedef	struct	s_format {
	int			len;
	int			flag;
	int			width;
	int			precision;
	char		conversion;
}				t_format;

/*
** libft
*/
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);

/*
** printf
*/
int				ft_putarg(t_format *format_info, va_list *args);
int				ft_print_main(const char *format, va_list *args, int len);
int				ft_printf(const char *format, ...);

/*
** format parser
*/
int				ft_flag(const char *format, t_format *format_info);
int				ft_width(const char *format, t_format *f_info, va_list *args);
int				ft_precision(const char *f, t_format *f_info, va_list *args);
int				ft_conversion(const char *format, t_format *format_info);
t_format		*format_parser(const char *f, t_format *f_info, va_list *args);

/*
** utils
*/
t_format		*ft_create_format_info(void);
void			ft_print_space(int count);
void			ft_print_zero(int count);
int				ft_numlen(unsigned int num);
void			ft_putunsignednbr_fd(unsigned int n, int fd);

char			*ft_decimal_to_hexa(unsigned long long num);
int				decide_retval(int width, int precision, int len);
void			ft_print_precision(int width, int precision, int len);

/*
** print by conversion
*/

int				ft_print_char(t_format *format_info, va_list *args);
int				ft_print_str(t_format *format_info, va_list *args);
int				ft_print_percent(t_format *format_info);

int				ft_zero_precision_retval(int width);
void			d_leftalign(t_format *f_info, int negative, int len, int num);
void			d_rightalign(t_format *f_info, int negative, int len, int num);
void			d_zeropadding(int width, int negative, int len, int num);
int				ft_print_decimal(t_format *format_info, va_list *args);

void			x_leftalign(int width, int precision, int len, char *hexa);
void			x_zeropadding(int width, int len, char *hexa);
void			x_rightalign(int width, int precision, int len, char *hexa);
char			*ft_str_toupper(char	*str, int len);
int				ft_print_hexa(t_format *f_info, va_list *args, char *option);

void			u_leftalign(int w, int p, int len, unsigned int num);
void			u_zeropadding(int width, int len, unsigned int num);
void			u_rigthalign(int w, int p, int len, unsigned int num);
int				ft_print_unsigned_decimal(t_format *format_info, va_list *args);

int				ft_print_pointer(t_format *format_info, va_list *args);

#endif
