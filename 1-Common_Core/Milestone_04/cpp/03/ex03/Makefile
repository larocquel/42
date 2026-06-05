# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/05 12:49:47 by leoaguia          #+#    #+#              #
#    Updated: 2026/06/05 18:39:59 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

# Binary Name
NAME		=	diamondtrap

# Compilation
CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow

# Files
SRCS		=	main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamonTrap.cpp

# Objects
OBJSDIR		=	obj/
OBJS		=	$(addprefix $(OBJSDIR), $(SRCS:.cpp=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJSDIR)%.o: %.cpp | $(OBJSDIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJSDIR):
		mkdir -p $(OBJSDIR)

clean:
		rm  -rf $(OBJSDIR)

fclean: clean
		rm  -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re