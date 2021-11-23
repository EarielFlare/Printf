/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:15:16 by cgregory          #+#    #+#             */
/*   Updated: 2021/11/20 09:18:20 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_return_wa(char **format)
{
	int	a;

	a = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	(*format)--;
	return (a);
}

static void	ft_find_opt(char **format, t_struct *s)
{
	if ((char)**format == '-')
		s->left_align = 1;
	else if ((char)**format == '0')
	{
		s->left_align = 0;
		s->zeroflag = 1;
	}
	else if ((char)**format == '#')
		s->sharp = 1;
	else if ((char)**format == ' ')
		s->space = 1;
	else if ((char)**format == '+')
		s->plus = 1;
}

int	ft_find_flag(char **format, t_struct *s)
{
	ft_init_struct(s);
	while (ft_strchr(STRFLAG, (int)**format) || ft_isdigit(**format))
	{
		ft_find_opt(format, s);
		if (ft_isdigit(**format) && (**format) != '0')
			s->width = ft_return_wa(format);
		if ((char)**format == '.')
		{
			(*format)++;
			s->accur = ft_return_wa(format);
			s->zeroflag = 0;
		}
		(*format)++;
	}
	if (s->zeroflag == 1)
		s->accur = s->width;
	return (0);
}

int	ft_find_div(const char *format, va_list ap, t_struct *s, int printed)
{
	if (ft_strchr(STRCONV, (int)*format))
	{
		if ((char)*format == 'c')
			printed += ft_putchar(va_arg(ap, int), s);
		if ((char)*format == 's')
			printed += ft_putstr(va_arg(ap, char *), s);
		if ((char)*format == 'd' || (char)*format == 'i')
			printed += ft_putnbr_cnt_di(va_arg(ap, int), s);
		if ((char)*format == 'u')
			printed += ft_putnbr_cnt_u(va_arg(ap, unsigned int), s);
		if ((char)*format == 'p')
			printed += ft_putnbr_p_ull(va_arg(ap, unsigned long), s);
		if ((char)*format == 'x')
			printed += ft_putnbr_16_ull(va_arg(ap, unsigned int), s, 'x');
		if ((char)*format == 'X')
			printed += ft_putnbr_16_ull(va_arg(ap, unsigned int), s, 'X');
		if ((char)*format == '%')
			printed += write(1, "%", 1);
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			printed;
	t_struct	s;

	printed = 0;
	if (!format[0])
	{
		write(1, "", 0);
		return (0);
	}
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_find_flag((char **)&(format), &s);
			printed = ft_find_div(format, ap, &s, printed);
		}
		else
			printed += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (printed);
}
