/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:18:31 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:18:31 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_count1(t_list **a, t_stack **stack)
{
	int		c;
	int		d;
	t_list	*tmp;

	c = 0;
	d = 0;
	tmp = *a;
	while (tmp->content != smallest(*a))
	{
		tmp = tmp->next;
		c++;
	}
	tmp = ft_dlstlast(*a);
	while (tmp->content != smallest(*a))
	{
		tmp = tmp->previous;
		d++;
	}
	while ((*a)->content != smallest(*a))
	{
		if (c > d)
			ft_reverse_rra(a, stack);
		else
			ft_rotate_a(*a, stack);
	}
}

static void	ft_return(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	while (*b != NULL)
	{
		if ((*b)->content == data->min)
			ft_push_a(b, a, stack);
		else
		{
			if ((*b)->content > biggest(*a))
				while ((*a)->content != smallest(*a))
					ft_count1(a, stack);
			else
				while ((*a)->content < (*b)->content)
					ft_rotate_a(*a, stack);
			ft_push_a(b, a, stack);
		}
	}
	while ((*a)->content != data->min)
		ft_count1(a, stack);
}

void	ft_five(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	data->min = smallest(*a);
	data->max = biggest(*a);
	if (ft_is_sort(*a) != 1)
	{
		ft_push_b(a, b, stack);
		ft_push_b(a, b, stack);
		ft_three(a, ft_dlstsize(*a), stack);
		ft_threeb(b, stack);
		ft_return(a, b, stack, data);
	}
}
