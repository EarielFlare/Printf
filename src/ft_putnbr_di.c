/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:24:41 by cgregory          #+#    #+#             */
/*   Updated: 2021/11/20 09:25:18 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

static int	ft_nbrrec_cnt(int nbr, int *printed)
{
	char	c;

	if (nbr == 0)
		return (0);
	else
	{
		c = nbr % 10;
		if (c < 0)
			c = -c;
		c = c + '0';
		nbr = nbr / 10;
		ft_nbrrec_cnt(nbr, printed);
		*printed += write(1, &c, 1);
	}
	return (0);
}

static void	ft_trash_cnt(int *tabs, int *nulls, t_struct *s, int n)
{
	s->w_len = ft_intlen(n);
	*tabs = s->width - s->accur;
	if (s->accur < s->w_len)
		*tabs = s->width - s->w_len;
	if (n < 0)
		(*tabs)--;
	if (n < 0 && s->zeroflag == 1)
		s->accur--;
	*nulls = s->accur - s->w_len;
}

static void	n_zero(int n, t_struct *s, int *printed)
{
	if (n == 0)
	{
		if (s->accur != 0)
			*printed += write(1, "0", 1);
		else if (s->width != 0)
			*printed += write(1, " ", 1);
	}
}

int	ft_putnbr_cnt_di(int n, t_struct *s)
{
	int	printed;
	int	tabs;
	int	nulls;

	printed = 0;
	ft_trash_cnt(&tabs, &nulls, s, n);
	if (s->left_align == 0)
		ft_wrsymb(tabs, &printed);
	if (n < 0)
		printed += write(1, "-", 1);
	if (s->plus == 1 && n >= 0)
		printed += write(1, "+", 1);
	else if (s->space == 1 && n >= 0)
		printed += write(1, " ", 1);
	while (nulls-- > 0)
		printed += write(1, "0", 1);
	n_zero(n, s, &printed);
	ft_nbrrec_cnt(n, &printed);
	if (s->left_align == 1)
		ft_wrsymb(tabs, &printed);
	return (printed);
}
