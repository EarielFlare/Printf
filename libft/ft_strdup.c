/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:45:44 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/11 20:04:40 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;

	mem = (char *)malloc(sizeof(const char) * (ft_strlen(s1) + 1));
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, ft_strlen(s1) + 1);
	return (mem);
}
