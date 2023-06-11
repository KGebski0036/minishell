/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commad_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:54:23 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/11 15:14:59 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*get_command_table(char **input)
{
	t_command	*com_tab;
	char		**splited_input;
	int			i;

	splited_input = ft_split(*input, '|');
	com_tab = malloc(sizeof(t_command)
			* (ft_get_number_of_words(*input, '|') + 1));
	i = -1;
	while (splited_input[++i])
	{
		com_tab[i].command = 0;
		com_tab[i].flags = 0;
		com_tab[i].arguments = 0;
		get_command(splited_input[i], &(com_tab[i]));
	}
	com_tab[i].command = 0;
	pc_clear_2d_tab(splited_input);
	return (com_tab);
}

void	get_command(char *str_command, t_command *command)
{
	int		i;

	i = 0;
	if (str_command[i] == ' ')
		str_command++;
	while (str_command[i] && str_command[i] != ' ')
		i++;
	command->command = ft_substr(str_command, 0, i);
	command->arguments = malloc(sizeof(char *) * 100);
	if (!str_command[i] || !str_command[i + 1])
		return ;
	i++;
	update_command_data(str_command, command, i);
}

void	update_flags(char *str_command, t_command *command, int i, int *j)
{
	char	*tmp;
	char	*tmp2;

	while (str_command[i + *j] != ' ' && str_command[i + *j])
		(*j)++;
	if (command->flags)
	{
		tmp2 = ft_substr(str_command, i + 1, (*j) - 1);
		tmp = ft_strjoin(command->flags, tmp2);
		free(command->flags);
		free(tmp2);
		command->flags = tmp;
	}
	else
		command->flags = ft_substr(str_command, i + 1, (*j) - 1);
}

void	update_command_data(char *str_command, t_command *command, int i)
{	
	int		j;
	int		k;

	k = 0;
	while (str_command[i])
	{
		j = 1;
		if (str_command[i] == '-')
			update_flags(str_command, command, i, &j);
		else if (is_quote(str_command[i]))
		{
			while (str_command[i + j] != str_command[i])
				j++;
			command->arguments[k++] = ft_substr(str_command, i + 1, j++ - 1);
		}
		else
		{
			while (str_command[i + j] != ' ' && str_command[i + j])
				j++;
			command->arguments[k++] = ft_substr(str_command, i, j);
		}
		while ((--j + 2) && str_command[i])
			i++;
	}
	command->arguments[k] = 0;
}
