/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:52:39 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/11 15:31:47 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pc_inti_envaiorment(t_env *env, char **env_var)
{
	pc_copy_env_variables(env, env_var);
	env->last_result = 0;
}
