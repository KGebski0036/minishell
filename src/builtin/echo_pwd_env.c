/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_pwd_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:25:13 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/16 16:26:49 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pc_echo_helper(t_command *command, int *new_line);

int	pc_echo(t_command command)
{
	int	new_line;
	int	ret_val;
	int	i;

	i = 0;
	new_line = 1;
	ret_val = pc_echo_helper(&command, &new_line);
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
	return (ret_val);
}

static int	pc_echo_helper(t_command *command, int *new_line)
{
	int	i;

	i = 0;
	if (command->flags)
	{
		while (command->flags[i])
		{
			if (command->flags[i++] != 'n')
			{
				ft_putstr_fd("Unregognized flag\n", 2);
				return (-1);
			}
		}
		if (command->flags[0] == 'n')
			*new_line = 0;
	}
	return (0);
}

int	pc_pwd(t_env *env)
{
	char	*tmp;

	tmp = pc_get_env_var(env, "PWD");
	if (!tmp || tmp[0] == '\0')
	{
		ft_putstr_fd("PWD variable is unset", 2);
		if (tmp[0] == '\0')
			free(tmp);
		return (2);
	}
	ft_putstr_fd(tmp, 1);
	ft_putstr_fd("\n", 1);
	free(tmp);
	return (0);
}

int	pc_env(t_command com, t_env *env)
{
	(void)com;
	pc_print_strings_tab(env->env_var);
	return (0);
}
