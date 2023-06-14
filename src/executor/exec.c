/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:23:32 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/13 19:57:47 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pc_file_redirection_check(t_command *command, t_env *env);

int	pc_exec_commands(t_command *commands, t_env *env)
{
	int	i;
	int fd_tmp;

	i = 0;
	pc_print_command_table(commands);
	// while (commands[i].command)
	// {
	// 	if (pipe(commands[i].fd) < 0)
	// 	{
	// 		ft_putstr_fd("Filed to create a pipe\n", 2);
	// 	}
	// }
	i = 0;
	while (commands[i].command)
	{
		fd_tmp = dup(1);
		pc_file_redirection_check(&(commands[i]), env);
		env->last_result = pc_exec_command(commands[i], env);
		dup2(fd_tmp, 1);
		i++;
	}
	return (env->last_result);
}

static void	pc_file_redirection_check(t_command *command, t_env *env)
{
	int i;
	int fd;

	i = 0;
	(void)env;
	while(command->arguments && command->arguments[i])
	{
		if(ft_strncmp(command->arguments[i], ">", 1) == 0)
		{
			if (ft_strncmp(command->arguments[i], ">>", 2) == 0)
				fd = open(command->arguments[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			else
				fd = open(command->arguments[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (fd == -1)
				return(ft_putstr_fd("Filed to handle a file\n", 2));
			dup2(fd, 1);
			free(command->arguments[i]);
			free(command->arguments[i + 1]);
			command->arguments[i] = 0;
			close(fd);
		}
		i++;
	}
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
