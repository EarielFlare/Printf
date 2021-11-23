/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:14:22 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/20 12:57:40 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_start;
	char	*s1_end;
	char	*str;
	char	*_s1;

	if (!s1 || !set || !*s1)
		return (ft_calloc(1, sizeof(char)));
	_s1 = (char *)s1;
	while (*_s1 && ft_strchr(set, *_s1))
		_s1++;
	if (!*_s1)
		return (ft_calloc(1, sizeof(char)));
	s1_start = (char *)_s1;
	_s1 = (char *)s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *_s1))
		_s1--;
	s1_end = (char *)_s1 + 1;
	str = ft_substr(s1, s1_start - s1, s1_end - s1_start);
	if (!str)
		return (NULL);
	return (str);
}
