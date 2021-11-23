/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:43:07 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/13 01:24:15 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*strcat;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strcat = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!strcat)
		return (NULL);
	ft_strlcpy(strcat, s1, s1_len + 1);
	ft_strlcpy(&strcat[s1_len], s2, s2_len + 1);
	return (strcat);
}
