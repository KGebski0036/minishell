/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:22:17 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/12 17:38:42 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pc_env(t_command com, t_env *env)
{
	(void)com;
	pc_print_strings_tab(env->env_var);
	return (0);
}

int	pc_export(t_command com, t_env *env)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_substr(com.arguments[0], 0, ft_strchrn(com.arguments[0], '='));
	pc_env_del_var(env, tmp);
	tmp2 = ft_substr(com.arguments[0], ft_strchrn(com.arguments[0], '=') + 1,
			ft_strlen(com.arguments[0]));
	pc_env_add_var(env, tmp, tmp2);
	return (0);
}

int	pc_unset(t_command com, t_env *env)
{
	char	*tmp;

	tmp = ft_substr(com.arguments[0], 0, ft_strchrn(com.arguments[0], '='));
	pc_env_del_var(env, tmp);
	return (0);
}
