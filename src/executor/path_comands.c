/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_comands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:30:32 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/13 01:05:17 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pc_serch_in_path(t_command com, t_env *env)
{
	int			i;
	char		*bin_path;
	char		**path;
	struct stat	file;

	path = ft_split(pc_get_env_var(env, "PATH"), ':');
	i = -1;
	while (path && path[++i])
	{
		if (ft_strncmp(com.command, path[i], ft_strlen(path[i])))
			bin_path = ft_strdup(com.command);
		else
			bin_path = ft_pathjoin(path[i], com.command);
		if (lstat(bin_path, &file) != -1)
		{
			pc_clear_2d_tab(path);
			if (pc_check_permision(file))
				return (pc_execute_path(path, bin_path, env, com));
		}
		else
			free(bin_path);
	}
	pc_clear_2d_tab(path);
	ft_putstr_fd("Unrecognized command", 2);
	return (1);
}

int	pc_check_permision(struct stat file)
{
	if (1)
	{
		if (file.st_mode & S_IXUSR)
			return (1);
		else
			ft_putstr_fd("File is not executable", 2);
	}
	else
		ft_putstr_fd("This is not a file", 2);
	return (0);
}

int	pc_execute_path(char **path, char *bin_path, t_env *env, t_command com)
{
	pid_t	pid;
	int		result;
	char	**argv;

	pid = fork();
	signal(SIGINT, pc_proc_signal_handler);
	if (pid == 0)
	{
		argv = pc_change_command_to_argv(com);
		result = execve(bin_path, argv, env->env_var);
	}
	else if (pid < 0)
	{
		pc_clear_2d_tab(path);
		free(bin_path);
		ft_putstr_fd("Fork failed", 2);
		return (-1);
	}
	wait(&pid);
	if (path)
		pc_clear_2d_tab(path);
	if (bin_path)
		free(bin_path);
	pc_clear_2d_tab(argv);
	return (result);
}

char	**pc_change_command_to_argv(t_command com)
{
	char	**argv;
	int		i;

	i = 0;
	while (com.arguments[i])
		i++;
	argv = malloc(sizeof(char *) * (i + 3));
	argv[0] = ft_strdup(com.command);
	argv[1] = ft_strjoin("-", com.flags);
	i = 0;
	while (com.arguments[i])
	{
		argv[2 + i] = ft_strdup(com.arguments[i]);
		i++;
	}
	argv[i] = 0;
	return (argv);
}
