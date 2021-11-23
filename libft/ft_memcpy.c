/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 03:08:10 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/10 19:54:50 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*_src;
	char		*_dst;

	_src = (const char *)src;
	_dst = (char *)dst;
	i = 0;
	while ((i != n) && ((_src) || (_dst)))
	{
		_dst[i] = _src[i];
		i++;
	}
	return ((void *)_dst);
}
