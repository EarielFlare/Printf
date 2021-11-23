/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:00:10 by cgregory          #+#    #+#             */
/*   Updated: 2021/10/13 05:11:46 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_nbrrec_fd(int nbr, int fd)
{
	char	c;

	if (nbr == 0)
		return ;
	else
	{
		c = nbr % 10;
		if (c < 0)
			c = -c;
		c = c + '0';
		nbr = nbr / 10;
		ft_nbrrec_fd(nbr, fd);
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write (fd, "-", 1);
	if (n == 0)
		write (fd, "0", 1);
	ft_nbrrec_fd(n, fd);
}
