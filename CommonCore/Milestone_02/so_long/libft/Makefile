# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 17:39:32 by leoaguia          #+#    #+#              #
#    Updated: 2025/06/22 00:24:41 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                         NAMES & PATHS & OBJECTS                              #
#==============================================================================#

NAME = libft.a

INCLUDES_DIR = .

PRINTF_SRCS = ./ft_printf/ft_printf.c ./ft_printf/ft_put_char.c \
./ft_printf/ft_put_digit.c ./ft_printf/ft_put_ptr.c ./ft_printf/ft_put_str.c
GNL_SRCS = ./get_next_line/get_next_line.c
SRCS = \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

#==============================================================================#
#                               COMPILATION                                    #
#==============================================================================#
CC = cc

CFLAGS = -Wall -Werror -Wextra

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

all: $(NAME)
$(NAME): $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make

.PHONY: all clean fclean re
