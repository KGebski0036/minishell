/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:56:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/09 14:10:16 by kgebski          ###   ########.fr       */
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
	int	stdi_fd;
	int	stdo_fd;
	int	erro_fd;

}	t_env;

//        -[ exec.c ]-        //
int		pc_exec_command(char *command);

//        -[ init.c ]-        //
void	pc_inti_envaiorment(t_env *env, char **env_var);
void	pc_copy_env_variables(t_env *env, char **env_var);

//        -[ print.c ]-        //
void	pc_print_strings_tab(char **tab);

#endif
