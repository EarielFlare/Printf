/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:48:53 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/21 21:08:24 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wrd_cnt(char const *s, char c)
{
	int	wc;
	int	flag;

	wc = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		if (flag == 0)
		{
			if (*s != c)
			{
				flag = 1;
				wc++;
			}
		}
		s++;
	}
	return (wc);
}

static void	free_mem(char **arr, int w_count)
{
	while (w_count)
	{
		if (arr[w_count - 1])
			free (arr[w_count - 1]);
		w_count--;
	}
	free (arr);
}

static char	**func_body(char **arr, const char *s, int wc, char c)
{
	int	i;
	int	w_count;
	int	w_len;

	i = 0;
	w_count = 0;
	while (w_count < wc)
	{
		while (s[i] == c)
			i++;
		w_len = 0;
		while (s[i + w_len] != c && s[i + w_len])
			w_len++;
		arr[w_count] = ft_substr(s, i, w_len);
		if (!arr[w_count])
		{
			free_mem(arr, w_count);
			return (NULL);
		}
		i += w_len;
		w_count++;
	}
	arr[w_count] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wc;

	if (!s)
		return (NULL);
	wc = wrd_cnt(s, c);
	arr = (char **)malloc((wc + 1) * sizeof (char const *));
	if (!arr)
		return (NULL);
	arr = func_body(arr, s, wc, c);
	return (arr);
}
