/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:11 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/11 23:10:40 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern struct termios	g_termios_save;

void	pc_reset_the_terminal(void)
{
	tcsetattr(0, 0, &g_termios_save);
	printf("OK");
}

void	pc_mod_term_atributes(t_env *env)
{
	int	rc;

	rc = tcgetattr(0, &g_termios_save);
	env->termios_new = g_termios_save;
	env->termios_new.c_lflag &= ~ECHOCTL;
	rc = tcsetattr(0, 0, &env->termios_new);
	if (rc)
	{
		perror("tcsetattr");
		exit(1);
	}
}

void	pc_start_minishell(t_env *env)
{
	char		*input;
	t_command	*commands;

	pc_mod_term_atributes(env);
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
		pc_exec_commands(commands, env);
		free(input);
	}
}
