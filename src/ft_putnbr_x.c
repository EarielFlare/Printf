/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:21:14 by cgregory          #+#    #+#             */
/*   Updated: 2021/11/20 09:21:20 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

static int	ft_nbrrec_cnt(char **base, unsigned int nbr, int *printed)
{
	char	c;

	if (nbr == 0)
		return (0);
	else
	{
		c = (*base)[nbr % 16];
		nbr = nbr / 16;
		ft_nbrrec_cnt(base, nbr, printed);
		*printed += write(1, &c, 1);
	}
	return (0);
}

static void	ft_trash_cnt(int *tabs, int *nulls, t_struct *s, unsigned int n)
{
	s->w_len = ft_intlen(n);
	*tabs = s->width - s->accur;
	if (s->accur < s->w_len)
		*tabs = s->width - s->w_len;
	*nulls = s->accur - s->w_len;
}

static void	n_zero(unsigned int n, t_struct *s, int *printed, char cs)
{
	if (n == 0)
	{
		if (s->accur != 0)
			*printed += write(1, "0", 1);
		else if (s->width != 0)
			*printed += write(1, " ", 1);
	}
	if (n != 0 && s->sharp == 1)
	{
		if (cs == 'x')
			*printed += write(1, "0x", 2);
		if (cs == 'X')
			*printed += write(1, "0X", 2);
	}
}

int	ft_putnbr_16_ull(unsigned int n, t_struct *s, char cs)
{
	int		printed;
	char	*base;
	int		tabs;
	int		nulls;

	if (cs == 'x')
		base = "0123456789abcdef";
	if (cs == 'X')
		base = "0123456789ABCDEF";
	printed = 0;
	ft_trash_cnt(&tabs, &nulls, s, n);
	if (s->left_align == 0)
		ft_wrsymb(tabs, &printed);
	while (nulls-- > 0)
		printed += write(1, "0", 1);
	n_zero(n, s, &printed, cs);
	ft_nbrrec_cnt(&base, n, &printed);
	if (s->left_align == 1)
		ft_wrsymb(tabs, &printed);
	return (printed);
}
