/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:56:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/10 15:21:09 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "color.h"
# include "libft.h"
# define MAX_COMMAND_LENGTH 1024
# define SHELL_PROMPT "PentaCode🐚 "
# define SHELL_SIGN "❯❯ "


typedef struct s_env
{
	int		stdi_fd;
	int		stdo_fd;
	int		erro_fd;

	char	**env_var;

}			t_env;

typedef struct s_command
{
	char	*command;
	char	*flags;
	char	**arguments;
}			t_command;

//      -[ minishell.c ]-      //
void	pc_start_minishell(t_env *env);

//        -[ exec.c ]-        //
int		pc_exec_command(char *command, t_env *env);

//        -[ init.c ]-        //
void		pc_inti_envaiorment(t_env *env, char **env_var);

//        -[ print.c ]-        //
void		pc_print_strings_tab(char **tab);

//     -[ env_variable.c ]-     //
void		pc_copy_env_variables(t_env *env, char **env_var);
char		*pc_get_env_var(t_env *env, char *name);
void		pc_env_add_var(t_env *env, char *name, char *val);
void		pc_env_del_var(t_env *env, char *name);

//        -[ clear.c ]-        //
void	pc_clear_env(t_env *env);
void	pc_clear_2d_tab(char **tab);

//        -[ signals.c ]-        //
void	pc_signals_interactive(void);
void	sigint_handler(int signal);

//        -[ parser.c ]-        //
t_command	*pc_parse_raw_input(char *input);
void		pc_interprete_vars(char **input);
void		pc_trim_input(char **input);
int			is_to_trim(char c);
int			is_quote(char c);
#endif
