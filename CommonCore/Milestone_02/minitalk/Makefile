# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 17:12:31 by leoaguia          #+#    #+#              #
#    Updated: 2025/05/04 16:58:48 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#

NAME = server
CLIENT_NAME = client
SERVER = server.c
CLIENT = client.c
OBJS_SERVER = $(SERVER:.c=.o)
OBJS_CLIENT = $(CLIENT:.c=.o)

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a

#==============================================================================#
#                            FLAGS & COMMANDS                                  #
#==============================================================================#

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

MAKE = make

#==============================================================================#
#                               RULES & DEPS                                   #
#==============================================================================#

all: $(LIBFT) $(NAME) $(CLIENT_NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJS_SERVER) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME)

$(CLIENT_NAME): $(OBJS_CLIENT) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -o $(CLIENT_NAME)

#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#

clean:
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	@$(RM) $(NAME) $(CLIENT_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
