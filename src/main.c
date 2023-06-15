/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:11:49 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/14 15:19:49 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 				Entry Function of Minishell
 * t_env	env			Struct for stroing vars acros the whole minishell
 * @param env_var		The Environment Variables passed to the program
 * @return int 			Status Code of Exiting Minishell
 */
int	main(int ac, char **av, char **env_var)
{
	t_env	env;
	int		exit_status;

	pc_init_environment(&env, env_var);
	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		t_command	*commands;
		char *com = ft_strdup(av[2]);
		commands = pc_parse_raw_input(&com, &env);
		exit_status = pc_exec_commands(commands, &env);
		free(com);
		exit(exit_status);
	}
	pc_echoctl_off();
	pc_signals_interactive();
	pc_start_minishell(&env);
	pc_clear_env(&env);
	return (0);
}
