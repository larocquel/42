# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 19:45:23 by leoaguia          #+#    #+#              #
#    Updated: 2025/05/22 22:39:50 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                             NAMES OF THE EXECUTABLES                         #
#******************************************************************************#

NAME           = push_swap
NAME_BONUS     = checker

#******************************************************************************#
#                           COMPILATION METHOD AND FLAGS                       #
#******************************************************************************#

CC    = cc
FLAGS = -Wall -Wextra -Werror -g

#******************************************************************************#
#                                   DIRECTORIES                                #
#******************************************************************************#

COMMANDS_DIR   = ./sources/commands
PW_DIR         = ./sources
INCLUDES       = ./includes
LIBFT_DIR      = ./libft
BONUS_DIR      = ./bonus

#******************************************************************************#
#                                  SOURCE FILES                                #
#******************************************************************************#

SRCS = $(COMMANDS_DIR)/swap.c \
       $(COMMANDS_DIR)/push.c \
       $(COMMANDS_DIR)/rev_rotate.c \
       $(COMMANDS_DIR)/rotate.c \
       $(PW_DIR)/utils.c \
       $(PW_DIR)/sort.c \
       $(PW_DIR)/sort_utils.c \
       $(PW_DIR)/error.c \
       $(PW_DIR)/init_stack.c \
       $(PW_DIR)/free.c \
       $(PW_DIR)/sort_utils_utils.c

BONUS       = $(BONUS_DIR)/bonus.c
MAIN        = $(PW_DIR)/main.c

#******************************************************************************#
#                 OBJECTS, FT_PRINTF, LIBFT  AND GNL INCLUSION                 #
#******************************************************************************#

SRCS_OBJ     = $(SRCS:.c=.o)
BONUS_OBJ    = $(BONUS:.c=.o)
MAIN_OBJ     = $(MAIN:.c=.o)
LIBFT        = $(LIBFT_DIR)/libft.a

#******************************************************************************#
#                                  BUILD TARGETS                               #
#******************************************************************************#

all: $(NAME)

$(NAME): $(SRCS_OBJ) $(MAIN_OBJ) $(LIBFT)
	$(CC) $(FLAGS) -I $(INCLUDES) $(SRCS_OBJ) $(MAIN_OBJ) -L $(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRCS_OBJ) $(BONUS_OBJ) $(LIBFT)
	$(CC) $(FLAGS) -I $(INCLUDES) -I $(BONUS_DIR) $(SRCS_OBJ) $(BONUS_OBJ) -L $(LIBFT_DIR) -lft -o $(NAME_BONUS)

#******************************************************************************#
#                            COMPILING DEPENDENCIES                            #
#******************************************************************************#

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -I $(BONUS_DIR) -c $< -o $@

#******************************************************************************#
#                                   CLEANING                                   #
#******************************************************************************#

clean:
	rm -rf $(SRCS_OBJ) $(BONUS_OBJ) $(MAIN_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean
		make all

.PHONY: all clean fclean re bonus
