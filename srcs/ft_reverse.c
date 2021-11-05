/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:48 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:17:49 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rra(t_list **a, t_stack **stack)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*new;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	last = ft_dlstlast(tmp);
	new = ft_dlstnew(last->content);
	ft_dlstadd_front(&tmp, new);
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	*a = new;
	(*a)->previous = NULL;
	ft_stack("rra", stack);
}

void	ft_reverse_rrb(t_list **b, t_stack **stack)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*new;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	last = ft_dlstlast(tmp);
	new = ft_dlstnew(last->content);
	ft_dlstadd_front(&tmp, new);
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	*b = new;
	(*b)->previous = NULL;
	ft_stack("rrb", stack);
}

void	ft_reverse_rr(t_list **a, t_list **b, t_stack **stack)
{
	ft_reverse_rra(a, stack);
	ft_reverse_rrb(b, stack);
}
