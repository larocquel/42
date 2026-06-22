# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 00:18:23 by leoaguia          #+#    #+#              #
#    Updated: 2026/05/25 18:00:54 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = violence

# Compilation
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

# Directories
OBJ_DIR     = obj/

# Source Files
SRCS        = main.cpp \
              Weapon.cpp \
              HumanA.cpp \
              HumanB.cpp

# Object Mapping
OBJS        = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

# Dependencies
DEPS        = Weapon.hpp \
              HumanA.hpp \
              HumanB.hpp

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