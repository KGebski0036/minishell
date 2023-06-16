/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:38:43 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/16 14:31:04 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*pc_parse_raw_input(char **input, t_env *env)
{
	pc_trim_input(input);
	if (!**input)
		return (0);
	pc_interprete_vars(input, env);
	if (!input)
		pc_quit(env, "failed to interprete var", 2);
	return (pc_get_command_table(input));
}

void	pc_interprete_vars(char **input, t_env *env)
{
	char	*result;

	result = (char *)malloc(ft_strlen(*input) * sizeof(char *));
	if (!result)
		pc_quit(env, "failed to alloc in interprete var", 2);
	pc_interpreting_vars(input, env, &result);
	free(*input);
	*input = result;
}

void	pc_trim_input(char **input)
{
	char	*result;
	char	quote;

	result = (char *)malloc(ft_strlen(*input) + 1);
	if (!result)
		pc_quit(0, "failed to trim input", 2);
	pc_trimming(input, &quote, &result);
	free(*input);
	if (quote != '\0')
	{
		free(result);
		*input = 0;
	}
	else
		*input = result;
}

void	pc_interpreting_vars(char **input, t_env *env, char **result)
{
	t_point	ji;

	ji.x = 0;
	ji.y = 0;
	while ((*input)[ji.x])
	{
		if ((*input)[ji.x] == '\'' && !pc_is_quote_closed(*input, ji.x))
		{
			(*result)[ji.y++] = (*input)[ji.x++];
			while ((*input)[ji.x] && (*input)[ji.x] != '\'')
				(*result)[ji.y++] = (*input)[ji.x++];
			if ((*input)[ji.x] == '\'')
				(*result)[ji.y++] = (*input)[ji.x++];
		}
		else if ((*input)[ji.x] == '$' && (*input)[ji.x + 1] != ' ')
		{
			pc_add_var_to_input(input, env, result, &ji);
		}
		else
			(*result)[ji.y++] = (*input)[ji.x++];
	}
	(*result)[ji.y] = '\0';
}

void	pc_add_var_to_input(char **input, t_env *env, char **result,
	t_point	*ji)
{
	int		k;
	int		h;
	char	*pathname;
	char	*pathval;

	k = ji->x + 1;
	while (ft_ispath_char((*input)[k]) && !pc_is_quote((*input)[k])
		&& (*input)[k])
		k++;
	pathname = ft_substr(*input, ji->x + 1, k - ji->x - 1);
	if (ft_strncmp(pathname, "?", 1) == 0)
		pathval = ft_itoa(env->last_result);
	else
		pathval = pc_get_env_var(env, pathname);
	h = 0;
	if (pathval)
		while (pathval[h])
			(*result)[ji->y++] = pathval[h++];
	ji->x += ft_strlen(pathname) + 1;
	free(pathname);
	free(pathval);
}
