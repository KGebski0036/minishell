/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:38:43 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/10 14:06:50 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*pc_parse_raw_input(char *input)
{
	pc_trim_input(&input);
	pc_interprete_vars(&input);
	ft_printf("%s\n", input);
	return (0);
}

void	pc_interprete_vars(char **input)
{
	char	*result;
	char	quote;
	int		i;

	result = (char *)malloc(ft_strlen(*input));
	if (!result)
	{
		free(input);
		input = 0;
	}
	i = 0;
	quote = '\0';
	while ((*input)[i])
	{
		if ((*input)[i] == '"' && !quote)
			quote = '"';
		else if (quote == (*input)[i])
		{
			quote = '\0';
		}

		i++;
	}
}

void	pc_trim_input(char **input)
{
	char	*result;
	char	quote;
	int		i;
	int		j;

	result = (char *)malloc(ft_strlen(*input));
	if (!result)
	{
		free(input);
		input = 0;
	}
	i = 0;
	j = 0;
	quote = '\0';
	while ((*input)[i] && is_to_trim((*input)[i]))
		i++;
	while ((*input)[i])
	{
		while ((*input)[i] && (!is_to_trim((*input)[i]) || quote))
		{
			if (quote == '\0' && is_quote((*input)[i]))
			{
				quote = (*input)[i];
			}
			else if (quote == (*input)[i])
			{
				quote = '\0';
			}
			result[j] = (*input)[i];
			j++;
			i++;

		}
		while ((*input)[i] && is_to_trim((*input)[i]))
			i++;
		if ((*input)[i])
			result[j++] = ' ';
	}
	//free(input);
	if (quote != '\0')
	{
		*input = 0;
		free(result);
	}
	else
		*input = result;
}

int	is_to_trim(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}
