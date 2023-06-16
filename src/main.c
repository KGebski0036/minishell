/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:11:49 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/16 14:30:58 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pc_tester(t_env *env, int ac, char **av);
static void	pc_start_minishell(t_env *env);

/**
 * @brief 				Entry Function of Minishell
 * t_env	env			Struct for stroing vars acros the program
 * @param env_var		The Environment Variables passed to the program
 * @return int 			Status Code of Exiting Minishell
 */
int	main(int ac, char **av, char **env_var)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(env));
	pc_copy_env_variables(&env, env_var);
	pc_tester(&env, ac, av);
	pc_mod_term_atributes_echoctl_off();
	pc_signals_interactive();
	pc_start_minishell(&env);
	pc_clear_env(&env);
	return (0);
}

static void	pc_start_minishell(t_env *env)
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
		if (!commands || commands[0].command == 0)
			continue ;
		env->last_result = pc_exec_commands(commands, env);
		pc_free_commands_tab(commands);
		free(input);
	}
}

/**
 * @brief  Performs a stylish exit from the program,
 * leaving a lasting impression.
 * @param msg Error message to be displayed.
 * @param failure Failure code indicating the type of exit.
 */
void	pc_quit(t_env *env, char *msg, int failure)
{
	pc_clear_env(env);
	if (failure == -1)
	{
		printf("%s%s%s\n", ERROR, msg, NC);
		exit(EXIT_FAILURE);
	}
	else if (!failure)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("%s%s%s\n", ERROR, msg, NC);
		exit(failure);
	}
}

static void	pc_tester(t_env *env, int ac, char **av)
{
	int		exit_status;

	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		t_command	*commands;
		char *com = ft_strdup(av[2]);
		commands = pc_parse_raw_input(&com, env);
		if (!commands)
			exit(2);
		exit_status = pc_exec_commands(commands, env);
		free(com);
		exit(exit_status);
	}
}