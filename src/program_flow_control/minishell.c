/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:11 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/15 16:40:14 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pc_start_minishell(t_env *env)
{
	char		*input;
	t_command	*commands;

	while (1)
	{
		pc_signals_interactive();
		input = readline(BLUE SHELL_PROMPT DARKBLUE SHELL_SIGN NC);
		if (input == NULL)
			break ;
		if (!input[0])
			continue ;
		add_history(input);
		commands = pc_parse_raw_input(&input, env);
		env->last_result = pc_exec_commands(commands, env);
		pc_free_commands_tab(commands);
		free(input);
	}
}
