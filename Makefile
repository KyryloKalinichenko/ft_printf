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
		ft_star.c

SRC2 = 	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \


OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ2)
	ar r $(NAME) $(OBJ) $(OBJ2)

clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
