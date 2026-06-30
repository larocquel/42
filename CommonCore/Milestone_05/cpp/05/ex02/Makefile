# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/27 22:17:46 by leoaguia          #+#    #+#              #
#    Updated: 2026/06/30 17:05:50 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

# Executable
NAME		= aform

# Compilation
CPP			= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror

# Files & Objects
SRCS		=	main.cpp					\
				Bureaucrat.cpp				\
				AForm.cpp					\
				ShrubberyCreationForm.cpp	\
				RobotomyRequestForm.cpp		\
				PresidentialPardonForm.cpp

OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

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