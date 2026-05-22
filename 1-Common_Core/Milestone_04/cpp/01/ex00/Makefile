# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 14:56:30 by leoaguia          #+#    #+#              #
#    Updated: 2026/05/22 23:20:01 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Leo <your_login@student.42porto.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 21:40:00 by Leo               #+#    #+#              #
#    Updated: 2026/05/22 21:40:00 by Leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = zombie

# Compilation
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

# Directories
OBJ_DIR     = obj/

# Files
SRCS        = main.cpp \
              Zombie.cpp \
              newZombie.cpp \
              randomChump.cpp

# Mapping
OBJS        = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

# Dependences
DEPS        = Zombie.hpp

# Rules
all: $(NAME)

# Link
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilation and obj/ creation
$(OBJ_DIR)%.o: %.cpp $(DEPS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	$(RM) $(OBJ_DIR)

# Full Clean
fclean: clean
	$(RM) $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re