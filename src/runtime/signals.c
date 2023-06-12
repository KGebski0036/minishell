/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:17:28 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/12 15:30:38 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pc_sigint_handler(int signal)
{
	if (signal)
	{
		rl_replace_line("", 0);
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	pc_sigquit_handler(int signal)
{
	if (signal)
	{
		exit(EXIT_FAILURE);
	}
}

void	pc_signals_interactive(void)
{
	signal(SIGINT, pc_sigint_handler);
	signal(SIGTSTP, pc_sigquit_handler);
	signal(SIGQUIT, SIG_IGN);
}
