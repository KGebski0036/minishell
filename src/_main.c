/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:11:49 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/10 18:48:56 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env_var)
{
	t_env	env;
	int		exit_status;

	pc_inti_envaiorment(&env, env_var);
	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		exit_status = pc_exec_command(av[2], &env);
		exit(exit_status);
	}
	pc_signals_interactive();
	pc_start_minishell(&env);
	pc_clear_env(&env);
}
