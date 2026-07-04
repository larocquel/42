# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/04 14:32:27 by leoaguia          #+#    #+#              #
#    Updated: 2026/07/04 16:38:35 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

# Executable
NAME		=	form

# Compilation
CPP			=	c++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror

# Files & Objects
SRCS		=	main.cpp Bureaucrat.cpp Form.cpp
OBJS_DIR	=	objs/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

# Rules

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re