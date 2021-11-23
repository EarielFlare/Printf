# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgregory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 21:14:39 by cgregory          #+#    #+#              #
#    Updated: 2021/11/20 09:32:19 by cgregory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

LIBFT_NAME		=	libft.a

SRCS_DIR		=	./src/

SRCS			=	$(SRCS_DIR)ft_funcs.c		$(SRCS_DIR)ft_printf.c\
					$(SRCS_DIR)ft_putstr.c		$(SRCS_DIR)ft_putchar.c\
					$(SRCS_DIR)ft_putnbr_di.c	$(SRCS_DIR)ft_putnbr_u.c\
					$(SRCS_DIR)ft_putnbr_p.c	$(SRCS_DIR)ft_putnbr_x.c

LIBFT			=	libft.h

LIBFT_DIR		=	./libft/

PRINTF			=	ft_printf.h

PRINTF_DIR		=	./inc/

OBJ				=	$(SRCS:%.c=%.o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

.PHONY			:	all bonus clean fclean re

all				:	$(LIBFT_NAME) $(NAME)

bonus			:	$(OBJ) $(PRINTF_DIR)$(PRINTF) $(LIBFT_DIR)$(LIBFT_NAME)
					ar rcs $(NAME) $? $(LIBFT_DIR)*.o

$(NAME)			:	$(OBJ) $(PRINTF_DIR)$(PRINTF) $(LIBFT_DIR)$(LIBFT_NAME)
					ar rcs $(NAME) $? $(LIBFT_DIR)*.o

$(LIBFT_NAME)	:	
					make all -C $(LIBFT_DIR)

%.o				:	%.c $(PRINTF_DIR)$(PRINTF)
					$(CC) $(CFLAGS) -I$(PRINTF_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean			:	
					rm -rf $(OBJ)
					make clean -C $(LIBFT_DIR)

fclean			:	clean
					rm -f $(NAME)
					make fclean -C $(LIBFT_DIR)

re				:	fclean all
