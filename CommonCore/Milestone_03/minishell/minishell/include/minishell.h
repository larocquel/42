/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:51:04 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/19 21:30:27 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* Libraries */
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <limits.h>

/* Structures */

/* Global var for signals */
extern volatile sig_atomic_t	g_signal;

/* Macros for the lexer (WORD = 0, PIPE = 1, ...) */
typedef enum e_type
{
	WORD,
	PIPE,
	R_IN,
	R_OUT,
	R_APP,
	R_HDC
}	t_type;

/* Token structure */
typedef struct s_token
{
	t_type			type;
	char			*value;
	int				quoted;
	struct s_token	*next;
}	t_token;

/* Redirection structure */
typedef struct s_redir
{
	t_type			type;
	char			*target;
	struct s_redir	*next;
}	t_redir;

/* Command structure */
typedef struct s_cmd
{
	char			**argv;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

/* Structure for environment variables */
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/* Main shell structure */
typedef struct s_shell
{
	t_env			*env_list;
	int				last_status;
	struct s_token	*tokens;
	struct s_cmd	*cmds;
}	t_shell;

/* Functions */

/* 01_main */
/* main.c */
void	execute_command(t_shell *sh, t_cmd *cmds);
void	run_shell(t_shell *sh);
/* cleanup.c */
void	free_tokens(t_token *tokens);
void	free_array(char **arr);
void	free_redirs(t_redir *r);
void	free_cmds(t_cmd *cmds);
void	free_env_list(t_env *env);

/* 02_parsing */
/* lexer.c */
t_token	*tokenize_line(const char *line);
/* lexer_utils.c */
t_token	*token_new(t_type type, const char *start, size_t len);
t_token	*token_new_owned(t_type type, char *value);
t_token	*token_new_op(t_type type);
int		token_add_back(t_token **lst, t_token *new_tok);
/* parser.c */
t_cmd	*parse_pipeline(t_shell *sh, t_token *tokens);
/* parser_utils.c */
int		redir_add_back(t_redir **lst, t_redir *new_r);
t_redir	*redir_new(t_type type, const char *target);
size_t	count_words_until_pipe(t_token *tok);
int		validate_syntax(t_shell *sh, t_token *tok);
/* expand.c */
void	expand_token(t_token *tok, t_shell *sh);
void	expand_all_tokens(t_shell *sh, t_token *tokens);
/* expand_utils.c */
char	*append_char(char *str, char c);
char	*append_str(char *base, char *val);
void	remove_quotes_final(char *str);

/* 03_exec */
/* exec.c */
void	execute_pipeline(t_shell *sh, t_cmd *cmds);
/* exec_simple.c */
void	exit_child(t_shell *sh, int status);
void	exec_simple_cmd(t_shell *sh, t_cmd *cmd);
/* exec_utils.c */
char	**env_to_array(t_env *env_list);
char	*find_executable(char *cmd, t_env *env_list);

/* 04_builtins */
/* builtins.c */
int		ft_exit(t_shell *sh, t_cmd *cmd);
int		ft_env(t_shell *sh, t_cmd *cmd);
int		ft_pwd(void);
int		ft_echo(t_cmd *cmd);
/* builtins_ops.c */
int		ft_cd(t_shell *sh, t_cmd *cmd);
int		ft_export(t_shell *sh, t_cmd *cmd);
int		ft_unset(t_shell *sh, t_cmd *cmd);
/* builtins_utils.c */
int		is_numeric(char *str);
int		check_n_flag(char *arg);
void	update_wd_env(t_shell *sh, char *old);
void	print_export_error(char *arg);
int		is_valid_key(char *str);
/* export_utils.c */
void	print_sorted_export(t_shell *sh);

/* 05_redirect */
/* redirect.c */
int		setup_redirects(t_cmd *cmd);
/* heredoc.c */
int		process_heredocs(t_shell *sh, t_cmd *cmds);
/* heredoc_utils.c */
char	*generate_heredoc_name(void);
int		check_expand_quotes(char *delimiter);
char	*get_var_content(t_shell *sh, char *line, int *i);

/* 06_env */
/* env.c */
void	init_env(t_shell *sh, char **envp);
char	*get_env_value(t_env *env, char *key);
void	env_update(t_shell *sh, char *key, char *value);
void	increment_shell_level(t_shell *sh);
/* env_utils.c */
t_env	*env_new(char *key, char *value);
void	env_add_back(t_env **lst, t_env *new_node);
t_env	*env_get_node(t_env *env, char *key);
void	env_remove_node(t_shell *sh, char *key);

/* 07_signals */
/* signals.c */
void	setup_signals_interactive(void);
void	setup_signals_child(void);
void	setup_signals_ignore(void);
void	setup_signals_heredoc(void);

#endif
