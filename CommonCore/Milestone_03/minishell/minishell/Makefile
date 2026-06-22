# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 15:49:02 by leoaguia          #+#    #+#              #
#    Updated: 2026/01/19 21:28:57 by leoaguia         ###   ########.fr        #
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
#                              ASCII ART DEFINITION                            #
# ============================================================================ #
define HEADER_ART
$(RED)
 (  `    )\ )  ( /(  )\ )  ( /(       )\ )  )\ )
 )\))(  (()/(  )\())(()/(  )\()) (   (()/( (()/(
((_)()\  /(_))((_)\  /(_))((_)\  )\   /(_)) /(_))
(_()((_)(_))   _((_)(_))   _((_)((_) (_))  (_))
|  \/  ||_ _| | \| ||_ _| | || || __|| |   | |
| |\/| | | |  | .` | | |  | __ || _| | |__ | |__
|_|  |_||___| |_|\_||___| |_||_||___||____||____|
$(RESET)
endef
export HEADER_ART

# ============================================================================ #
#                                   VARIABLES                                  #
# ============================================================================ #
NAME        = minishell
MAKEFLAGS   += --no-print-directory

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RLFLAGS     = -lreadline

SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -Iinclude -I$(LIBFT_DIR)/inc

SRC         = $(SRC_DIR)/01_main/main.c                 \
              $(SRC_DIR)/01_main/cleanup.c              \
              $(SRC_DIR)/02_parsing/lexer.c             \
              $(SRC_DIR)/02_parsing/lexer_utils.c       \
              $(SRC_DIR)/02_parsing/parser.c            \
              $(SRC_DIR)/02_parsing/parser_utils.c      \
              $(SRC_DIR)/02_parsing/expand.c            \
              $(SRC_DIR)/02_parsing/expand_utils.c      \
              $(SRC_DIR)/03_exec/exec.c                 \
              $(SRC_DIR)/03_exec/exec_simple.c          \
              $(SRC_DIR)/03_exec/exec_utils.c           \
              $(SRC_DIR)/04_builtins/builtins.c         \
              $(SRC_DIR)/04_builtins/builtins_ops.c     \
              $(SRC_DIR)/04_builtins/builtins_utils.c   \
              $(SRC_DIR)/04_builtins/export_utils.c     \
              $(SRC_DIR)/05_redirect/redirect.c         \
              $(SRC_DIR)/05_redirect/heredoc.c          \
              $(SRC_DIR)/05_redirect/heredoc_utils.c    \
              $(SRC_DIR)/06_env/env.c                   \
              $(SRC_DIR)/06_env/env_utils.c             \
              $(SRC_DIR)/07_signals/signals.c           \
              $(SRC_DIR)/07_signals/signals_utils.c

OBJ         = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ============================================================================ #
#                                     RULES                                    #
# ============================================================================ #
all: $(LIBFT) $(NAME)

# Supression file creation (Silent)
sup:
	@echo "{\n   leak readline\n   Memcheck:Leak\n   ...\n   fun:readline\n}\n{\n   leak add_history\n   Memcheck:Leak\n   ...\n   fun:add_history\n}" > readline.supp

# Build Libft (Silent call)
$(LIBFT): sup
	@$(MAKE) -C $(LIBFT_DIR)

# Link Minishell
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAGS) -o $(NAME)
	@echo "$(GREEN)Minishell compiled successfully!$(RESET)"
	@printf "$$HEADER_ART"

# Compile Minishell Objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CYAN)[MINISHELL] Compiling: $(WHITE)$<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(BLUE)[MINISHELL] Objects cleaned.$(RESET)"

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME) readline.supp
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)[MINISHELL] Binary removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re sup