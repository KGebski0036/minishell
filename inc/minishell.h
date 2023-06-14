/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:56:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/14 12:14:01 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>

# include "color.h"
# include "libft.h"
# define MAX_COMMAND_LENGTH 1024
# define SHELL_PROMPT "PentaCode🐚 "
# define SHELL_SIGN "❯❯ "

typedef struct s_env
{
	char			**env_var;
	int				last_result;
}			t_env;

typedef struct s_command
{
	char	*command;
	char	*flags;
	char	**arguments;
	int		fd[2];
	int		pid;
}			t_command;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

//      -[ termios.c ]         //
void		pc_echoctl_on(void);
void		pc_echoctl_off(void);

//      -[ minishell.c ]-      //
void		pc_start_minishell(t_env *env);
void		pc_reset_the_terminal(void);
void		pc_mod_term_atributes(t_env *env);

//        -[ exec.c ]-        //
int			pc_exec_commands(t_command *commands, t_env *env);
int			pc_exec_command(t_command command, t_env *env);

//        -[ init.c ]-        //
void		pc_init_environment(t_env *env, char **env_var);

//        -[ print.c ]-        //
void		pc_print_strings_tab(char **tab);
void		pc_print_command_table(t_command *commands);

//     -[ env_variable.c ]-     //
void		pc_copy_env_variables(t_env *env, char **env_var);
char		*pc_get_env_var(t_env *env, char *name);
void		pc_env_add_var(t_env *env, char *name, char *val);
void		pc_env_del_var(t_env *env, char *name);

//        -[ clear.c ]-        //
void		pc_clear_env(t_env *env);
void		pc_clear_2d_tab(char **tab);
void		pc_free_commands_tab(t_command *commands);

//        -[ signals.c ]-        //
void		pc_signals_interactive(void);
void		pc_proc_signal_handler(int signo);

//        -[ parser.c ]-        //
t_command	*pc_parse_raw_input(char **input, t_env *env);
void		pc_interprete_vars(char **input, t_env *env);
void		pc_trim_input(char **input);
void		pc_interpreting_vars(char **input, t_env *env, char **result);
void		pc_add_var_to_input(char **input, t_env *env, char **result,
				t_point	*ji);

//        -[ parser_helper.c ]-        //
void		pc_check_quote(char **input, int i, char *quote);
void		pc_trimming(char **input, char *quote, char	**result);
int			pc_is_to_trim(char c);
int			pc_is_quote(char c);
int			pc_is_quote_closed(char *str, int n);

//        -[ command_table.c ]-        //
t_command	*pc_get_command_table(char **input);
void		pc_get_command(char *str_com, t_command *command);
void		pc_update_flags(char *str_com, t_command *command, int i, int *j);
void		pc_update_command_data(char *str_com, t_command *command, int i);
void		pc_add_arg(t_command *command, int *k, char *arg);

//        -[ exit.c ]-        //
void		pc_quit(t_env *env, char *msg, int failure);

//        -[ buildins.c ]-        //
int			pc_echo(t_command command);
int			pc_cd(t_command command, t_env *env);
int			pc_exit(t_command com, t_env *env);
int			pc_pwd(t_command com, t_env *env);

//        -[ buildins2.c ]-        //
int			pc_env(t_command command, t_env *env);
int			pc_export(t_command command, t_env *env);
int			pc_unset(t_command com, t_env *env);

//        -[ path_commands.c ]-        //
int			pc_serch_in_path(t_command com, t_env *env);
int			pc_check_permision(struct stat file);
int			pc_execute_path(char *bin_path, t_env *env, t_command com);
char		**pc_change_command_to_argv(t_command com);
#endif
