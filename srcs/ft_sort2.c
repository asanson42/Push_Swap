/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:18:05 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:18:06 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_min(int chunk, int min, int max)
{
	int	band;

	band = ((max - min) / 5);
	if (chunk == 1)
		return (min);
	if (chunk == 2)
		return (min + band);
	return (min + (band * (chunk - 1)));
}

int	chunk_max(int chunk, int min, int max)
{
	int	band;

	band = ((max - min) / 5);
	if (chunk == 1)
		return (min + band);
	if (chunk > 1 && chunk < 5)
		return (min + (band * chunk) - 1);
	return (max);
}

int	first_or_second(t_list *lst, int hold_first, int hold_second)
{
	int		count_f;
	int		count_s;
	t_list	*tmp;

	count_f = 0;
	count_s = 0;
	tmp = ft_dlstlast(lst);
	while (lst->content != hold_first)
	{
		count_f++;
		lst = lst->next;
	}
	while (tmp->content != hold_second)
	{
		count_s++;
		tmp = tmp->previous;
	}
	if (count_f < count_s || count_f == count_s)
		return (1);
	return (0);
}

int	ft_middle(t_list *a, int hold)
{
	int		i;
	int		mid;
	t_list	*middle;

	i = 1;
	middle = a;
	mid = ft_dlstsize(middle) / 2;
	while (a->content != hold)
	{
		a = a->next;
		i++;
	}
	if (i < mid || i == mid)
		return (1);
	return (0);
}
