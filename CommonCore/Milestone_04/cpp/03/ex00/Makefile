# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/04 13:43:09 by leoaguia          #+#    #+#              #
#    Updated: 2026/06/04 15:13:23 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

# Binary Name
NAME		=	claptrap

# Compilation
CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror

# Files
SRCS		=	main.cpp ClapTrap.cpp

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