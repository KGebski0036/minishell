/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:56:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/09 15:21:06 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include "color.h"
# include "libft.h"

typedef struct s_env
{
	int		stdi_fd;
	int		stdo_fd;
	int		erro_fd;

	char	**env_var;

}	t_env;

//        -[ exec.c ]-        //
int		pc_exec_command(char *command);

//        -[ init.c ]-        //
void	pc_inti_envaiorment(t_env *env, char **env_var);

//        -[ print.c ]-        //
void	pc_print_strings_tab(char **tab);

//     -[ env_variable.c ]-     //
void	pc_copy_env_variables(t_env *env, char **env_var);
char	*pc_get_env_var(t_env *env, char *name);
void	pc_env_add_var(t_env *env, char *name, char *val);
void	pc_env_del_var(t_env *env, char *name);

//        -[ clear.c ]-        //
void	pc_clear_env(t_env *env);
void	pc_clear_2d_tab(char **tab);

#endif
