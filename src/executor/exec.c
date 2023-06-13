/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:23:32 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/13 18:48:42 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pc_exec_commands(t_command *commands, t_env *env)
{
	int	i;

	i = 0;
	while (commands[i].command)
	{
		if (pipe(commands[i].fd) < 0)
			pc_quit(env, "Filed to create a pipe\n", 2);
		i++;
	}
	i = 0;
	while (commands[i].command && commands[i + 1].command)
	{
		commands[0].fd[0] = 0;
		commands[i].fd[1] = commands[i + 1].fd[0];
		i++;
	}
	commands[i].fd[1] = 1;
	pc_print_command_table(commands);
	i = 0;
	while (commands[i].command)
	{
		env->last_result = pc_exec_command(commands[i++], env);
	}
	i = 0;
	while (commands[i].command)
	{
		close(commands[i].fd[0]);
		close(commands[i].fd[1]);
		i++;
	}
	return (env->last_result);
}

int	pc_exec_command(t_command command, t_env *env)
{
	ft_str_tolower(command.command);
	if (ft_strncmp(command.command, "echo", ft_strlen(command.command)) == 0)
		return (pc_echo(command));
	if (ft_strncmp(command.command, "cd", ft_strlen(command.command)) == 0)
		return (pc_cd(command, env));
	if (ft_strncmp(command.command, "exit", ft_strlen(command.command)) == 0)
		return (pc_exit(command, env));
	if (ft_strncmp(command.command, "pwd", ft_strlen(command.command)) == 0)
		return (pc_pwd(command, env));
	if (ft_strncmp(command.command, "env", ft_strlen(command.command)) == 0)
		return (pc_env(command, env));
	if (ft_strncmp(command.command, "export", ft_strlen(command.command)) == 0)
		return (pc_export(command, env));
	if (ft_strncmp(command.command, "unset", ft_strlen(command.command)) == 0)
		return (pc_unset(command, env));
	return (pc_serch_in_path(command, env));
}
