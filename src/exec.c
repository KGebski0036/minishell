/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:23:32 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/11 19:44:03 by kgebski          ###   ########.fr       */
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
		env->last_result = pc_exec_command(commands[i++]);
	}
	pc_free_commands_tab(commands);
	return (0);
}

int	pc_exec_command(t_command command)
{
	if (ft_strncmp(command.command, "echo", ft_strlen(command.command)) == 0)
		return (pc_echo(command));
	return (-1);
}
