# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 13:50:51 by imaman-s          #+#    #+#              #
#    Updated: 2022/05/11 13:50:52 by imaman-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

CFILE = ft_atoi.c ft_error.c ft_intcpy.c \
		ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_strchr.c ft_strcmp.c ft_strdel.c \
		ft_strdup.c ft_strjoin.c ft_strlen.c \
		ft_strsplit.c ft_strsub.c get_next_line.c


OFILE = $(CFILE:.c=.o)

all: $(NAME)

$(NAME): $(OFILE) libft.h
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean:
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all