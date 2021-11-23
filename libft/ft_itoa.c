/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:26:43 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/13 05:11:17 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dig_count(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*strfill(char *str, int count, int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -sign;
	while (count--)
	{
		str[count] = (n % 10) * sign + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = dig_count(n);
	if (n <= 0)
		count = count + 1;
	str = (char *)ft_calloc((count + 1), sizeof(char));
	if (!str)
		return (NULL);
	str = strfill(str, count, n);
	if (n < 0)
		str[0] = '-';
	return (str);
}
