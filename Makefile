# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 09:54:41 by kkalinic          #+#    #+#              #
#    Updated: 2021/02/11 16:08:02 by kkalinic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

SRC = 		ft_atoi.c \
		ft_isdigit.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_substr.c \
		ft_itoa.c \
		ft_printf.c \
		ft_flags.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_calloc.c \
		ft_bzero.c \
		ft_strdup.c \
		ft_strcmp.c \
		ft_isalpha.c \
		ft_load.c \
		ft_percent.c \
		ft_putstr.c \
		ft_print_ptr.c \
		ft_itoa_max.c \
		ft_skip.c \
		ft_parcing_conv.c \
		ft_printnum.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)

bonus: $(OBJ) 
	ar r $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	rm -f $(NAME)

bonus: all

re: fclean all

.PHONY: clean fclean all re
