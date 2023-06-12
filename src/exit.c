/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:55:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/12 13:57:15 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief  Performs a stylish exit from the program,
 * leaving a lasting impression.
 * @param msg Error message to be displayed.
 * @param failure Failure code indicating the type of exit.
 */
void	pc_quit(t_env *env, char *msg, int failure)
{
	(void)env;
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
