/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:20:23 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/16 18:40:57 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	m_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
	{
		m_len = s_len - start;
		if (m_len > len)
			m_len = len;
	}
	else
		m_len = 0;
	substr = (char *)ft_calloc(m_len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	while (start--)
		s++;
	ft_strlcpy(substr, s, m_len + 1);
	return (substr);
}
