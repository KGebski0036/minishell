/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:52:39 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/09 14:09:01 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pc_inti_envaiorment(t_env *env, char **env_var)
{
	env->stdi_fd = dup(0);
	env->stdo_fd = dup(1);
	env->erro_fd = dup(2);
	pc_copy_env_variables(env, env_var);
}

void	pc_copy_env_variables(t_env *env, char **env_var)
{
	(void)env;
	pc_print_strings_tab(env_var);
}
