/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:23:32 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/11 14:16:10 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pc_exec_command(t_command *commands, t_env *env)
{
	(void)env;
	pc_print_command_table(commands);
	pc_free_commands_tab(commands);
	return (0);
}
