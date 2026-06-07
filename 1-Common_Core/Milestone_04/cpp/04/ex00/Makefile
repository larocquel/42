# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/07 10:53:47 by leoaguia          #+#    #+#              #
#    Updated: 2026/06/07 14:26:05 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

NAME		=	animal

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJSDIR		=	obj/
OBJS		=	$(addprefix $(OBJSDIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJSDIR)%.o: %.cpp | $(OBJSDIR)
				$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJSDIR):
				mkdir -p $(OBJSDIR)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re