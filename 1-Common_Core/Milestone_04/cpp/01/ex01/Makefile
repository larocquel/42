# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 01:06:35 by leoaguia          #+#    #+#              #
#    Updated: 2026/05/24 03:13:24 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

NAME        = horde

# Compilation
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

# Directories
OBJ_DIR     = obj/

# Source Files
SRCS        = main.cpp \
              Zombie.cpp \
              zombieHorde.cpp

# Object Mapping
OBJS        = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

# Dependencies
DEPS        = Zombie.hpp

# Default Rule
all: $(NAME)

# Executable Linking
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Object Compilation & Directory Creation
$(OBJ_DIR)%.o: %.cpp $(DEPS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Object Files
clean:
	$(RM) $(OBJ_DIR)

# Full Clean (Objects & Executable)
fclean: clean
	$(RM) $(NAME)

# Rebuild Project
re: fclean all

.PHONY: all clean fclean re