/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:08:58 by cgregory          #+#    #+#             */
/*   Updated: 2021/11/20 09:29:20 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	strnull(char *str, t_struct *s, int *tabs, int *toprint)
{
	if (str == NULL)
	{
		if (s->accur == -1)
		{
			*tabs = *tabs - 6;
			*toprint = 6;
		}
		if (s->accur >= 0)
		{
			*toprint = s->accur;
			if (*toprint > 6)
				*toprint = 6;
		}
	}
}

int	ft_putstr(char *str, t_struct *s)
{
	int	printed;
	int	tabs;
	int	toprint;

	tabs = 0;
	printed = 0;
	toprint = s->accur;
	s->w_len = ft_strlen(str);
	if (s->w_len < s->accur || s->accur == -1)
		toprint = s->w_len;
	strnull(str, s, &tabs, &toprint);
	tabs = s->width - toprint;
	if (s->left_align == 0)
		ft_wrsymb(tabs, &printed);
	if (str == NULL)
		printed += write(1, "(null)", toprint);
	else
		printed += write(1, str, toprint);
	if (s->left_align == 1)
		ft_wrsymb(tabs, &printed);
	return (printed);
}
