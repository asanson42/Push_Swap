/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:18:23 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:18:25 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_repush(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	hold;

	if (data->chunk != 1)
		rot_or_rev_a(a, smallest(*a), stack);
	while (ft_dlstsize(*b) > 0)
	{
		hold = biggest(*b);
		rot_or_rev_b(b, hold, stack);
		ft_push_a(b, a, stack);
	}
}

void	ft_hundred(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	before;

	data->chunk = 1;
	data->min = smallest(*a);
	data->max = biggest(*a);
	before = 1;
	while (data->chunk <= 5)
	{
		while (before == 1)
			before = before_push(a, b, stack, data);
		ft_repush(a, b, stack, data);
		data->chunk++;
		if (data->chunk > 5)
		{
			rot_or_rev_a(a, data->min, stack);
			return ;
		}
		before = before_push(a, b, stack, data);
	}
}

void	ft_fivehundred(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	before;

	data->chunk = 1;
	data->min = smallest(*a);
	data->max = biggest(*a);
	before = 1;
	while (data->chunk <= 8)
	{
		while (before == 1)
			before = fbefore_push(a, b, stack, data);
		ft_repush(a, b, stack, data);
		data->chunk++;
		if (data->chunk > 8)
		{
			rot_or_rev_a(a, data->min, stack);
			return ;
		}
		before = fbefore_push(a, b, stack, data);
	}
}
