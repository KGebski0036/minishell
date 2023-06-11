/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:52:06 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/11 21:49:42 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pc_echo(t_command command)
{
	int	new_line;
	int	i;

	i = 0;
	new_line = 1;
	if (command.flags)
	{
		while (command.flags[i])
		{
			if (command.flags[i++] != 'n')
			{
				ft_putstr_fd("Unregognized flag", 2);
				return (-1);
			}
		}
		if (command.flags[0] == 'n')
			new_line = 0;
	}
	i = 0;
	if (command.arguments && command.arguments[0] != NULL)
	{
		ft_putstr_fd(command.arguments[i++], 1);
		while (command.arguments[i])
		{
			ft_putstr_fd(" ", 1);
			ft_putstr_fd(command.arguments[i++], 1);
		}
	}
	if (new_line)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	pc_cd(t_command command, t_env *env)
{
	char	*home;

	if (command.arguments[0] == NULL)
	{
		home = pc_get_env_var(env, "HOME");
		if (home == NULL)
		{
			ft_putstr_fd("The HOME variable is not set", 2);
			return (1);
		}
		if (chdir(home) != 0)
		{
			ft_putstr_fd("The HOME variable is not valid", 2);
			return (1);
		}
	}
	else
	{
		if (chdir(command.arguments[0]) != 0)
		{
			ft_putstr_fd("cd: No such file or directory", 2);
			return (1);
		}
	}
	return (0);
}