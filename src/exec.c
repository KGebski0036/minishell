/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:23:32 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/11 22:09:57 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pc_exec_commands(t_command *commands, t_env *env)
{
	int	i;

	i = 0;
	//pc_print_command_table(commands);
	while (commands[i].command)
	{
		env->last_result = pc_exec_command(commands[i++], env);
	}
	pc_free_commands_tab(commands);
	//printf("%i", env->last_result);
	return (env->last_result);
}

int	pc_exec_command(t_command command, t_env *env)
{
	ft_str_tolower(command.command);
	if (ft_strncmp(command.command, "echo", ft_strlen(command.command)) == 0)
		return (pc_echo(command));
	if (ft_strncmp(command.command, "cd", ft_strlen(command.command)) == 0)
		return (pc_cd(command, env));
	return (-1);
}
