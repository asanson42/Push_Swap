/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:42 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:17:43 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_list **a, t_list **b, t_stack **stack)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*new;

	if (!*a)
		return ;
	first = *a;
	new = ft_dlstnew(first->content);
	ft_dlstadd_front(b, new);
	tmp = *a;
	first->previous = NULL;
	*a = first->next;
	free(tmp);
	ft_stack("pb", stack);
}

void	ft_push_a(t_list **b, t_list **a, t_stack **stack)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*new;

	if (!*b)
		return ;
	first = *b;
	new = ft_dlstnew(first->content);
	ft_dlstadd_front(a, new);
	tmp = *b;
	first->previous = NULL;
	*b = first->next;
	free(tmp);
	ft_stack("pa", stack);
}
