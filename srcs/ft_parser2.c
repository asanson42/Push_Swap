/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:23 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:17:26 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_int_min(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) >= 12)
		return (1);
	if (ft_strlen(str) == 11)
	{
		if (str[i] == '-')
			i++;
		if (ft_strcmp((str + i), "2147483648") > 0)
			return (1);
	}
	return (0);
}

static int	ft_int_max(char *str)
{
	if (ft_strlen(str) > 10)
		return (1);
	if (ft_strlen(str) == 10)
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (1);
	}
	return (0);
}

int	global_check(char **str, int size)
{	
	int	i;
	int	is_big;

	i = 0;
	is_big = 0;
	if (check_str(str, size))
		return (1);
	if (check_double(str, size))
		return (1);
	while (i < size)
	{
		if (str[i][0] == '-')
			is_big = ft_int_min(str[i]);
		else
			is_big = ft_int_max(str[i]);
		if (is_big == 1)
			return (1);
		i++;
	}
	return (0);
}
