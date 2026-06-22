# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/27 04:14:19 by leoaguia          #+#    #+#              #
#    Updated: 2026/05/27 05:37:28 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = dontbesed

CC          = c++
CFLAGS      = -std=c++98 -Wall -Wextra -Werror
RM          = rm -rf

OBJ_DIR     = obj/

SRCS        = main.cpp \
              SedLoser.cpp

INCS        = SedLoser.hpp

OBJS        = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp $(INCS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.replace

re: fclean all

.PHONY: all clean fclean re