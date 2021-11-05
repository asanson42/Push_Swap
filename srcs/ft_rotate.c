/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:54 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:17:55 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list *a, t_stack **stack)
{
	t_list	*tmp;
	int		high;

	if (!a || !a->next)
		return ;
	high = a->content;
	tmp = a->next;
	while (a->next)
	{
		tmp = a->next;
		a->content = tmp->content;
		a = a->next;
	}
	a->content = high;
	a->next = NULL;
	ft_stack("ra", stack);
}

void	ft_rotate_b(t_list *b, t_stack **stack)
{
	t_list	*tmp;
	int		high;

	if (!b || !b->next)
		return ;
	high = b->content;
	tmp = b->next;
	while (b->next)
	{
		tmp = b->next;
		b->content = tmp->content;
		b = b->next;
	}
	b->content = high;
	b->next = NULL;
	ft_stack("rb", stack);
}

void	ft_rotate_rr(t_list *a, t_list *b, t_stack **stack)
{
	ft_rotate_a(a, stack);
	ft_rotate_b(b, stack);
}
