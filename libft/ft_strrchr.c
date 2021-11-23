/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:04:03 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/15 21:41:21 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	while (i)
	{
		if (s[i - 1] == (char)c)
			return ((char *)(&s[i - 1]));
		i--;
	}
	return (NULL);
}
