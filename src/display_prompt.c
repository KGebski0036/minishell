/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:53:48 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/09 16:33:57 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(void)
{
	// if (g_msh.exit_status == EXIT_SUCCESS)
		// ft_putstr(GREEN);
	// else
		// ft_putstr(RED);
	ft_printf("%s~/42-workspace/minishell-workspace/42-minishell-vog\n%s",BLUE, NC);
	ft_printf("%s❯%s ",BLUE, NC);
}
