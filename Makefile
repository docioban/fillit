# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: docioban <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 08:09:25 by docioban          #+#    #+#              #
#    Updated: 2017/12/13 01:26:55 by docioban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = *.c

OBJ = $(SRC:.c=.o)

SRCL = libft/*.c

OBJL = $(SRCL:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -o $(NAME) -L. $(LIBFT) $(OBJ)

$(LIBFT): $(OBJL)
	ar rc $(LIBFT) $(OBJL)
	ranlib $(LIBFT)

$(OBJL): $(SRCL)
	$(CC) -c $(SRCL)
	mv *.o libft

clean:
	rm -f $(OBJ) $(OBJL)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all
