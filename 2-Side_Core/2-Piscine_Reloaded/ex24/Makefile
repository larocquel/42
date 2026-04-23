# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 16:46:25 by leoaguia          #+#    #+#              #
#    Updated: 2024/10/18 20:08:59 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCSDIR = srcs

INCLUDES = includes

SRCS =	$(SRCDIR)/ft_putchar.c \
		$(SRCDIR)/ft_putstr.c \
		$(SRCDIR)/ft_strcmp.c \
		$(SRCDIR)/ft_strlen.c \
		$(SRCDIR)/ft_swap.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

