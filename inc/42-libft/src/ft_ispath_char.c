/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispath_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:21:52 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/15 16:43:31 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * @brief function checks if 'val' is a alphabetic character (a-z & A-Z)
 * 
 * @param c parameter that gets checked
 * @return returns int 1 if parameter is alphanumeric or 0 if not.
 */
int	ft_ispath_char(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| c == '?' || c == '_')
		return (1);
	return (0);
}
