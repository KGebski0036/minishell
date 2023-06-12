/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:56:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/12 00:55:22 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
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
	struct termios	termios_new;
}			t_env;

typedef struct s_command
{
	char	*command;
	char	*flags;
	char	**arguments;
}			t_command;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

//      -[ minishell.c ]-      //
void		pc_start_minishell(t_env *env);
void		pc_reset_the_terminal(void);
void		pc_mod_term_atributes(t_env *env);

//        -[ exec.c ]-        //
int			pc_exec_commands(t_command *commands, t_env *env);
int			pc_exec_command(t_command command, t_env *env);

//        -[ init.c ]-        //
void		pc_inti_envaiorment(t_env *env, char **env_var);

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
// void		pc_sigint_handler(int signal);
void		pc_signals_interactive(void);

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
void		pc_exit(t_env *env, char *msg, int failure);

//        -[ buildins.c ]-        //
int			pc_echo(t_command command);
int			pc_cd(t_command command, t_env *env);
#endif
