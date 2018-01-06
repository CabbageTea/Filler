# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 14:24:42 by dglaser           #+#    #+#              #
#    Updated: 2018/01/01 22:54:50 by dglaser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./

NAME = libft.a

SRC = ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_atoi.c \
	  ft_isprint.c \
	  ft_strdup.c \
	  ft_memccpy.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memcpy.c \
	  ft_strclr.c \
	  ft_strequ.c \
	  ft_isupper.c \
	  ft_islower.c \
	  ft_strnequ.c \
	  ft_putendl.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_memalloc.c \
	  ft_strnew.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_itoa.c \
	  ft_intlen.c \
	  ft_memdel.c \
	  ft_strdel.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strtrim.c \
	  ft_putnbr_fd.c \
	  ft_wstrlen.c \
	  ft_strncat.c \
	  ft_strnstr.c \
	  ft_memmove.c \
	  ft_strsplit.c\
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_isspace.c \
	  ft_putintstr.c \
	  ft_putnbrmax.c \
	  ft_un_putnbr.c \
	  ft_putnbrunmax.c \
	  ft_unintlen.c \
	  ft_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
# $(NAME):
# 	gcc -Werror -Wall -Wextra -c $(SRC)
# 	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
