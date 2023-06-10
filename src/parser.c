/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:38:43 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/10 18:15:49 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*pc_parse_raw_input(char **input, t_env *env)
{
	pc_trim_input(input);
	pc_interprete_vars(input, env);
	return (0);
}

int	glg(char *str, int n)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (i < n)
	{
		if (str[i] == '"')
			count++;
		i++;
	}
	return (count % 2);
}

void	pc_interprete_vars(char **input, t_env *env)
{
	char	*result;
	char	*pathname;
	char	*pathval;
	int		i;
	int		j;
	int		k;
	int		h;

	result = (char *)malloc(ft_strlen(*input) + 100);
	if (!result)
	{
		free(*input);
		*input = 0;
	}
	i = 0;
	j = 0;
	while ((*input)[i])
	{
		if ((*input)[i] == '\'' && !glg(*input, i))
		{
			result[j++] = (*input)[i++];
			while ((*input)[i] && (*input)[i] != '\'')
				result[j++] = (*input)[i++];
			if ((*input)[i] == '\'')
				result[j++] = (*input)[i++];
		}
		else if ((*input)[i] == '$' && (*input)[i + 1] != ' ')
		{
			k = i + 1;
			while (((*input)[k] != ' ' && (*input)[k] != '"'
					&& (*input)[k] != '\'') && (*input)[k])
				k++;
			pathname = ft_substr(*input, i + 1, k - i - 1);
			pathval = pc_get_env_var(env, pathname);
			h = 0;
			if (pathval)
				while (pathval[h])
					result[j++] = pathval[h++];
			i += ft_strlen(pathname) + 1;
		}
		else
			result[j++] = (*input)[i++];
	}
	result[j] = '\0';
	free(*input);
	*input = result;
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
	result[j] = '\0';
	free(*input);
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
