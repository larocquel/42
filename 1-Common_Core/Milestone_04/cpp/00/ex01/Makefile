# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/12 21:48:27 by leoaguia          #+#    #+#              #
#    Updated: 2026/04/29 01:58:08 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME		=	phonebook

# Compilation
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

# Diretories
OBJ_DIR		=	obj/

# Files & Objects
SRCS		=	Main.cpp 		\
				Contact.cpp		\
				PhoneBook.cpp	\

INCS		=	Contact.hpp		\
				PhoneBook.hpp	\

OBJS		=	$(SRCS:%.cpp=$(OBJ_DIR)%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
		@echo "Executable $(NAME) created successfully!"

$(OBJ_DIR)%.o: %.cpp $(INCS) | $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@echo "Object files removed!"

fclean: clean
		rm -f $(NAME)
		@echo "Executable $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re