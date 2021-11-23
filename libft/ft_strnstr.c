/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:11:18 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/15 23:22:29 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ndllen;
	char	*_haystack;

	i = 0;
	ndllen = ft_strlen(needle);
	_haystack = (char *)haystack;
	if (ndllen == 0 || *needle == 0)
		return ((char *)haystack);
	if (len == 0
		|| ft_strlen(haystack) < ndllen)
		return (NULL);
	while (*haystack && i <= (len - ndllen))
	{
		if (0 == ft_strncmp(_haystack, needle, ndllen))
			return ((char *)_haystack);
		_haystack++;
		i++;
	}
	return (NULL);
}
