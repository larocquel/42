# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 17:41:22 by leoaguia          #+#    #+#              #
#    Updated: 2024/11/25 17:13:22 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables for output file, compiler, flags

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_put_char.c ft_put_digit.c ft_put_ptr.c ft_put_str.c
OBJS = $(SRCS:.c=.o)

# Rules

# all: Compile the lib
# ar creates/modify libftprintf.a
# r tells ar to  insert OBJS into the libftprintf.a
# c tells ar to create the archive if it does not exist
# s creats a index for each function in libftprintf.a
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile each .c file to .o (object file)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Rule to clean object files
clean:
	rm -f $(OBJS)

# Rule to clean all files (object and library)
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (clean + all)
re: fclean all

# Avoid Conflicts with Files
# By marking these targets as phony, you're telling make that these are not files, but just commands to execute.
# This ensures make always runs the associated commands, even if a file with the same name exists.
.PHONY: all clean fclean re
