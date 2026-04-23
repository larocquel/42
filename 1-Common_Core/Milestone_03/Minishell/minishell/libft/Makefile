# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 17:39:32 by leoaguia          #+#    #+#              #
#    Updated: 2026/01/06 23:45:03 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#                                     COLORS                                   #
# ============================================================================ #

RESET       = \033[0;39m
GRAY        = \033[0;90m
RED         = \033[0;91m
GREEN       = \033[0;92m
YELLOW      = \033[0;93m
BLUE        = \033[0;94m
MAGENTA     = \033[0;95m
CYAN        = \033[0;96m
WHITE       = \033[0;97m

# ============================================================================ #
#                                   VARIABLES                                  #
# ============================================================================ #

NAME        =   libft.a
CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror -I inc

# Directories
SRC_DIR     =   src
OBJ_DIR     =   obj
INC_DIR     =   inc

# Source Files
SRC_CTYPE   =   ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
                ft_isprint.c ft_tolower.c ft_toupper.c

SRC_MEM     =   ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c \
                ft_memcpy.c ft_memmove.c ft_memset.c

SRC_IO      =   ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

SRC_LST     =   ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
                ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
                ft_lstnew.c ft_lstsize.c

SRC_STR     =   ft_atoi.c ft_itoa.c ft_split.c ft_strchr.c ft_strdup.c \
                ft_striteri.c ft_strjoin.c ft_strjoin3.c ft_strlcat.c \
                ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
                ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
                ft_strcmp.c

SRC_PRINTF  =   ft_printf.c ft_put_char.c ft_put_digit.c ft_put_ptr.c \
                ft_put_str.c

SRC_GNL     =   get_next_line.c

# Concatenate all
SRCS        =   $(addprefix $(SRC_DIR)/ctype/, $(SRC_CTYPE)) \
                $(addprefix $(SRC_DIR)/memory/, $(SRC_MEM)) \
                $(addprefix $(SRC_DIR)/io/, $(SRC_IO)) \
                $(addprefix $(SRC_DIR)/list/, $(SRC_LST)) \
                $(addprefix $(SRC_DIR)/string/, $(SRC_STR)) \
                $(addprefix $(SRC_DIR)/printf/, $(SRC_PRINTF)) \
                $(addprefix $(SRC_DIR)/gnl/, $(SRC_GNL))

OBJS        =   $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# ============================================================================ #
#                                     RULES                                    #
# ============================================================================ #

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Libft compiled successfully!$(RESET)"

# Compiling Objects with Custom Message
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)[LIBFT] Compiling: $(WHITE)$<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)[LIBFT] Object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[LIBFT] Binary removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re