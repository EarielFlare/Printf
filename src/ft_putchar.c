/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:54:10 by cgregory          #+#    #+#             */
/*   Updated: 2021/11/20 09:15:33 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_struct *s)
{
	int	printed;
	int	tabs;

	tabs = 0;
	printed = 0;
	s->w_len = 1;
	tabs = s->width - s->w_len;
	if (s->left_align == 0)
		ft_wrsymb(tabs, &printed);
	printed += write(1, &c, 1);
	if (s->left_align == 1)
		ft_wrsymb(tabs, &printed);
	return (printed);
}
