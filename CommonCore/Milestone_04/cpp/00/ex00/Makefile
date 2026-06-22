# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/11 03:14:03 by leoaguia          #+#    #+#              #
#    Updated: 2026/04/29 02:07:07 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable
NAME		= megaphone

# Compilation
CPP			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror

# Files & Objects
SRCS		= megaphone.cpp
OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

# Rules

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
