/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:49:26 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/14 16:02:45 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pc_file_redirection_check(t_command *command, t_env *env)
{
	char		*input;
	// char		*input2;
	int i;
	int fd;

	i = 0;
	(void)env;
	while (command->arguments && command->arguments[i])
	{
		if(ft_strncmp(command->arguments[i], ">", 1) == 0)
		{
			if (ft_strncmp(command->arguments[i], ">>", 2) == 0)
				fd = open(command->arguments[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			else
				fd = open(command->arguments[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (fd == -1)
				return(ft_putstr_fd("Filed to handle a file\n", 2));
			dup2(fd, 1);
			free(command->arguments[i]);
			free(command->arguments[i + 1]);
			command->arguments[i] = 0;
			close(fd);
			break;
		}
		else if (ft_strncmp(command->arguments[i], "<<", 2) == 0)
		{
			fd = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
			while(1)
			{
				input = readline(BLUE DARKBLUE SHELL_SIGN NC);
				if(ft_strncmp(input, command->arguments[i + 1], sizeof(input)) == 0)
				{
					free(input);
					break ;
				}
				ft_putstr_fd(input, fd);
				ft_putstr_fd("\n", fd);
				free(input);
			}
			close(fd);
			fd = open("heredoc", O_RDONLY, 0777);
			dup2(fd, 0);
			free(command->arguments[i]);
			free(command->arguments[i + 1]);
			command->arguments[i] = 0;
			close(fd);
			break;
		}
		else if (ft_strncmp(command->arguments[i], "<", 1) == 0)
		{
			fd = open(command->arguments[i + 1], O_RDONLY, 0777);
			if (fd == -1)
				return(ft_putstr_fd("Filed to handle a file\n", 2));
			dup2(fd, 0);
			free(command->arguments[i]);
			free(command->arguments[i + 1]);
			command->arguments[i] = 0;
			close(fd);
			break;
		}
		i++;
	}
}
