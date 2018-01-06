# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 21:22:25 by dglaser           #+#    #+#              #
#    Updated: 2018/01/05 21:31:55 by dglaser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = filler.a

PROGRAMNAME = filler

SRC = main.c \
	  get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar rcs $(NAME) $(OBJ) libft/*.o
clean:
	/bin/rm -f *.o
	make -C libft/ clean

fclean:
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all
