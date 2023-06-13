/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:37:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/13 00:17:48 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pc_clear_env(t_env *env)
{
	pc_clear_2d_tab(env->env_var);
}

void	pc_clear_2d_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

void	pc_free_commands_tab(t_command *commands)
{
	int	i;

	i = 0;
	while (commands[i].command)
	{
		if (commands[i].command)
			free(commands[i].command);
		if (commands[i].flags)
			free(commands[i].flags);
		if (commands[i].arguments[0] != 0 && commands[i].arguments)
			pc_clear_2d_tab(commands[i].arguments);
		i++;
	}
	free(commands);
}
