/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 05:42:58 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/10 20:46:10 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*_s;
	unsigned char	_c;

	i = 0;
	_s = (unsigned char *)s;
	_c = (unsigned char)c;
	while (n--)
	{
		if (_s[i] == _c)
			return ((void *)(&_s[i]));
		i++;
	}
	return ((void *) NULL);
}
