/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:18:46 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:18:47 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(t_list *dlst)
{
	int	small;

	small = dlst->content;
	while (dlst != NULL)
	{
		if (dlst->content < small)
			small = dlst->content;
		dlst = dlst->next;
	}
	return (small);
}

int	biggest(t_list *dlst)
{
	int	big;

	big = dlst->content;
	while (dlst != NULL)
	{
		if (dlst->content > big)
			big = dlst->content;
		dlst = dlst->next;
	}
	return (big);
}
