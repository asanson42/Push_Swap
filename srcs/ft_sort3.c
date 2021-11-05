/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:18:13 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:18:17 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_or_rev_a(t_list **a, int hold, t_stack **stack)
{
	int	mid;

	mid = ft_middle(*a, hold);
	if (mid == 1)
		while ((*a)->content != hold)
			ft_rotate_a(*a, stack);
	else
		while ((*a)->content != hold)
			ft_reverse_rra(a, stack);
}

void	rot_or_rev_b(t_list **b, int hold, t_stack **stack)
{
	int	mid;

	mid = ft_middle(*b, hold);
	if (mid == 1)
		while ((*b)->content != hold)
			ft_rotate_b(*b, stack);
	else
		while ((*b)->content != hold)
			ft_reverse_rrb(b, stack);
}

int	fbefore_push(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int		hold_first;
	int		hold_second;
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		data->c_min = chunk_min_five(data->chunk, data->min, data->max);
		data->c_max = chunk_max_five(data->chunk, data->min, data->max);
		if (tmp->content >= data->c_min && tmp->content <= data->c_max)
		{
			hold_first = scan_next(*a, data->c_min, data->c_max);
			hold_second = scan_back(*a, data->c_min, data->c_max);
			if (first_or_second(*a, hold_first, hold_second) == 1)
				rot_or_rev_a(a, hold_first, stack);
			else
				rot_or_rev_a(a, hold_second, stack);
			ft_push_b(a, b, stack);
			return (1);
		}
		else
			tmp = tmp->next;
	}
	return (0);
}

int	before_push(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int		hold_first;
	int		hold_second;
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		data->c_min = chunk_min(data->chunk, data->min, data->max);
		data->c_max = chunk_max(data->chunk, data->min, data->max);
		if (tmp->content >= data->c_min && tmp->content <= data->c_max)
		{
			hold_first = scan_next(*a, data->c_min, data->c_max);
			hold_second = scan_back(*a, data->c_min, data->c_max);
			if (first_or_second(*a, hold_first, hold_second) == 1)
				rot_or_rev_a(a, hold_first, stack);
			else
				rot_or_rev_a(a, hold_second, stack);
			ft_push_b(a, b, stack);
			return (1);
		}
		else
			tmp = tmp->next;
	}
	return (0);
}
