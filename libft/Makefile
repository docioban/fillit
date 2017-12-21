# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: docioban <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 07:25:09 by docioban          #+#    #+#              #
#    Updated: 2017/12/12 15:56:21 by docioban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS= -Wall -Wextra -Werror

NAME= libft.a

SRC = *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): libft.h
	$(CC) $(CFLAGS) -c $(SRC) -I.
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
