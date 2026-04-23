# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 17:39:32 by leoaguia          #+#    #+#              #
#    Updated: 2025/05/04 17:21:15 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#

NAME = libft.a

HEADER_PATH = ./libft.h
MANDATORY_PATH = ./mandatory
PRINTF_PATH = ./printf/src

MANDATORY_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

PRINTF_FILES = ft_printf.c ft_put_char.c ft_put_digit.c ft_put_ptr.c ft_put_str.c

SRCS = $(addprefix $(MANDATORY_PATH)/, $(MANDATORY_FILES))
PRINTF_SRCS = $(addprefix $(PRINTF_PATH)/, $(PRINTF_FILES))

OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

#==============================================================================#
#                            FLAGS & COMMANDS                                  #
#==============================================================================#
CC = cc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

AR = ar rcs

MAKE = make

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

all: extra $(NAME)

%.o: %.c $(HEADER_PATH)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

extra: $(OBJS) $(PRINTF_OBJS)
	@$(AR) $(NAME) $(OBJS) $(PRINTF_OBJS)

#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#
clean:
	@$(RM) -f $(OBJS) $(PRINTF_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all extra clean fclean re
