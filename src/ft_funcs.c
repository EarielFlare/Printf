/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:33:44 by cgregory          #+#    #+#             */
/*   Updated: 2021/11/20 09:16:15 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_struct *s)
{
	s->width = 0;
	s->accur = -1;
	s->w_len = 0;
	s->left_align = 0;
	s->zeroflag = 0;
	s->sharp = 0;
	s->space = 0;
	s->plus = 0;
}

void	ft_wrsymb(int tabs, int *printed)
{
	while (tabs-- > 0)
		*printed += write(1, " ", 1);
}
