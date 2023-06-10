/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:11 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/10 18:54:08 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pc_reset_the_terminal(void)
{
	tcsetattr(0, 0, &g_termios_save); // Restoring the original terminal attributes
	printf("OK");
}

void	pc_mod_term_atributes(t_env *env)
{
	int rc;

	rc = tcgetattr(0, &g_termios_save); // Getting the current terminal attributes
	env->termios_new = g_termios_save;
	env->termios_new.c_lflag &= ~ECHOCTL; // Disabling printing of control characters
	rc = tcsetattr(0, 0, &env->termios_new); // Applying the modified terminal attributes
	if (rc) {
		perror("tcsetattr");
		exit(1);
	}
}

void	pc_start_minishell(t_env *env)
{
	char	*input;

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
		pc_parse_raw_input(&input, env);
		pc_exec_command(input, env);
		free(input);
	}
}
