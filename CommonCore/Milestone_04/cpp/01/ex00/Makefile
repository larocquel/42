# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 14:56:30 by leoaguia          #+#    #+#              #
#    Updated: 2026/05/23 23:57:57 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

NAME        = zombie

# Compilation
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

# Directories
OBJ_DIR     = obj/

# Source Files
SRCS        = main.cpp \
              Zombie.cpp \
              newZombie.cpp \
              randomChump.cpp

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