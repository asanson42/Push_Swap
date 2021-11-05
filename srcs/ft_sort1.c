/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:18:00 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:18:01 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_min_five(int chunk, int min, int max)
{
	int	band;

	band = ((max - (min)) / 8);
	if (chunk == 1)
		return (min);
	if (chunk == 2)
		return (min + band);
	return (min + (band * (chunk - 1)));
}

int	chunk_max_five(int chunk, int min, int max)
{
	int	band;

	band = ((max - (min)) / 8);
	if (chunk == 1)
		return (min + band);
	if (chunk > 1 && chunk < 8)
		return (min + (band * chunk) - 1);
	return (max);
}

int	ft_is_chunk(t_list *lst, int c_min, int c_max)
{
	if (lst->content >= c_min && lst->content <= c_max)
		return (1);
	return (0);
}

int	scan_next(t_list *lst, int c_min, int c_max)
{
	while (lst != NULL)
	{
		if (ft_is_chunk(lst, c_min, c_max) == 1)
			return (lst->content);
		lst = lst->next;
	}
	return (0);
}

int	scan_back(t_list *lst, int c_min, int c_max)
{
	lst = ft_dlstlast(lst);
	while (lst != NULL)
	{
		if (ft_is_chunk(lst, c_min, c_max) == 1)
			return (lst->content);
		lst = lst->previous;
	}
	return (0);
}
