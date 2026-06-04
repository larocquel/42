# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/04 13:43:09 by leoaguia          #+#    #+#              #
#    Updated: 2026/06/04 14:08:38 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

Name		=	claptrap

CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror
RM			=	rm -rf

SRCS		=	main.cpp ClapTrap.cpp

OBJSDIR		=	obj/
OBJS		=	$(addprefix $(OBJSDIR), $(SRS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJSDIR)%.o: %.cpp | $(OBJSDIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJSDIR):
		mkdir -p $(OBJSDIR)

clean:
		$(RM) $(OBJSDIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re