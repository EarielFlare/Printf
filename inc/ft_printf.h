/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:40:59 by cgregory          #+#    #+#             */
/*   Updated: 2021/11/20 09:31:03 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STRCONV "cspdiuxX%"
# define STRFLAG "+- #0."
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_struct
{			
	int	width;
	int	accur;
	int	w_len;
	int	left_align;
	int	zeroflag;
	int	sharp;
	int	space;
	int	plus;
}	t_struct;
int		ft_printf(const char *format, ...);
int		ft_putnbr_cnt_di(int n, t_struct *s);
int		ft_putnbr_cnt_u(unsigned int n, t_struct *s);
int		ft_putnbr_p_ull(unsigned long n, t_struct *s);
int		ft_putnbr_16_ull(unsigned int n, t_struct *s, char cs);
int		ft_putchar(char c, t_struct *s);
int		ft_putstr(char *str, t_struct *s);
void	ft_init_struct(t_struct *s);
void	ft_wrsymb(int tabs, int *printed);
int		ft_find_flag(char **format, t_struct *s);
int		ft_find_div(const char *format, va_list ap, t_struct *s, int printed);
#endif
