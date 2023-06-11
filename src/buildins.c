/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:52:06 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/11 19:45:01 by kgebski          ###   ########.fr       */
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
	if (command.arguments)
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
