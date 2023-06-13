/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:17:28 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/13 00:09:08 by kgebski          ###   ########.fr       */
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

void	pc_proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		signal(SIGINT, SIG_DFL);
	}
}
