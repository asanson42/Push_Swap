/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:19:07 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:19:09 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list *a, t_stack **stack)
{
	int	tmp;
	int	tmp2;

	tmp = a->content;
	tmp2 = a->next->content;
	a->content = tmp2;
	a->next->content = tmp;
	ft_stack("sa", stack);
}

void	ft_swap_b(t_list *b, t_stack **stack)
{
	int	tmp;
	int	tmp2;

	tmp = b->content;
	tmp2 = b->next->content;
	b->content = tmp2;
	b->next->content = tmp;
	ft_stack("sb", stack);
}

void	ft_swap_ss(t_list *a, t_list *b, t_stack **stack)
{
	ft_swap_a(a, stack);
	ft_swap_b(b, stack);
}
