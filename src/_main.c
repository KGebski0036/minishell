/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:11:49 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/09 16:34:18 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env_var)
{
	t_env	env;
	int		exit_status;

	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		exit_status = pc_exec_command(av[2]);
		exit(exit_status);
	}
	pc_inti_envaiorment(&env, env_var);
    // Set up signal handlers
    signal(SIGINT, ctrlC_handler);          // ctrl-C
    signal(SIGQUIT, ctrlBackslash_handler); // ctrl-\
    // Enable EOF detection for ctrl-D
    if (signal(SIGINT, ctrlD_handler) == SIG_ERR)
    {
        printf("Error setting up signal handler for ctrl-D.\n");
        return 1;
    }
    // Main loop
    while (1)
    {
        // Read user input
        char input[100];
		display_prompt();
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            // Handle input error (e.g., Ctrl+D)
            printf("Exiting the shell.\n");
            break;
        }
        // Process user input...
    }
}
