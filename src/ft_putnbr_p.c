/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:22:39 by cgregory          #+#    #+#             */
/*   Updated: 2021/11/20 09:23:24 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned long n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static int	ft_nbrrec_cnt(char **base, unsigned long nbr, int *printed)
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

static void	ft_trash_cnt(int *tabs, t_struct *s, unsigned long n)
{
	s->w_len = ft_intlen(n);
	*tabs = s->width - s->accur - 2;
	if (s->accur < s->w_len)
		*tabs = s->width - s->w_len - 3;
	if (n != 0)
		(*tabs)++;
}

int	ft_putnbr_p_ull(unsigned long n, t_struct *s)
{
	int		printed;
	char	*base;
	int		tabs;

	base = "0123456789abcdef";
	printed = 0;
	ft_trash_cnt(&tabs, s, n);
	if (s->left_align == 0)
		ft_wrsymb(tabs, &printed);
	printed += write(1, "0x", 2);
	if (n == 0 && s->accur == -1)
		printed += write(1, "0", 1);
	ft_nbrrec_cnt(&base, n, &printed);
	if (s->left_align == 1)
		ft_wrsymb(tabs, &printed);
	return (printed);
}
