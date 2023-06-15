/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:23:32 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/15 00:10:24 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pc_exec_commands(t_command *commands, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (commands[i].command)
	{
		if (pipe(commands[i].fd) < 0)
			pc_quit(env, "Filed to create a pipe\n", 2);
		i++;
	}
	i = 0;
	while (commands[i].command)
	{
		env->last_result = pc_child_proces_command(&commands, env, i);
		i++;
	}
	//ft_printf("resut - %i\n", env->last_result);
	j = 0;
	while (commands[j].command)
	{
		close(commands[j].fd[0]);
		close(commands[j].fd[1]);
		j++;
	}
	i = -1;
	while (commands[++i].command)
		waitpid(commands[i].pid, NULL, 0);
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

int	pc_child_proces_command(t_command **commands, t_env *env, int i)
{
	int	j;
	int	result;

	(*commands)[i].pid = fork();
	if ((*commands)[i].pid == -1)
		pc_quit(env, "Filed to create a fork\n", 2);
	if ((*commands)[i].pid == 0)
	{
		j = -1;
		while ((*commands)[++j].command)
		{
			if (i != j)
				close((*commands)[j].fd[1]);
			if (i - 1 != j)
				close((*commands)[j].fd[0]);
		}
		pc_file_redirection_check(&((*commands)[i]));
		if ((*commands)[i + 1].command)
			dup2((*commands)[i].fd[1], STDOUT_FILENO);
		if (i != 0)
			dup2((*commands)[i - 1].fd[0], STDIN_FILENO);
		env->last_result = pc_exec_command((*commands)[i], env);
		close((*commands)[i].fd[1]);
		if (i != 0)
			close((*commands)[i - 1].fd[0]);
		exit(env->last_result);
	}
	wait(&result);
	env->last_result = result;
	return (result);
}
