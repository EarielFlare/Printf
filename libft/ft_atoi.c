/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:09:53 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/19 08:38:55 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	nmbr;

	sign = 1;
	nmbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nmbr = nmbr * 10 + (*str - '0');
		str++;
	}
	if (nmbr > 2147483647 && sign == 1)
		return (-1);
	if (nmbr > 2147483648 && sign == -1)
		return (0);
	return (sign * (int)nmbr);
}
