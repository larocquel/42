# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/11 03:14:03 by leoaguia          #+#    #+#              #
#    Updated: 2026/04/11 04:05:36 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable
NAME		= megaphone

# Compilation
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror

# Paths
SRCS		= megaphone.cpp
OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

# Rules

# Main rule
all: $(NAME)

# Executable linking
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile .o files into objs/ directory
$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Object cleanup rule
clean:
	rm -rf $(OBJS_DIR)

# Full cleanup rule (objects + executable)
fclean: clean
		rm -f $(NAME)

# Rebuild rule
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re
