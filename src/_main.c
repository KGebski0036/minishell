/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:11:49 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/10 15:18:27 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env_var)
{
	t_env	env;
	int		exit_status;

	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		exit_status = pc_exec_command(av[2]);
		exit(exit_status);
	}
	pc_inti_envaiorment(&env, env_var);
	pc_clear_env(&env);
}
