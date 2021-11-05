/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:18:53 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:18:58 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack(char *str)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}

static t_stack	*stack_last(t_stack *s)
{
	t_stack	*s_tmp;

	if (!s)
		return (NULL);
	s_tmp = s;
	while (s_tmp->next)
		s_tmp = s_tmp->next;
	return (s_tmp);
}

static void	stack_add_back(t_stack **as, t_stack *new_s)
{
	t_stack	*s_last;

	if (!new_s || !as)
		return ;
	if (!*as)
	{
		*as = new_s;
		return ;
	}
	s_last = stack_last(*as);
	new_s->next = NULL;
	s_last->next = new_s;
}

void	stack_clear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (*stack)
	{
		current = *stack;
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*stack = NULL;
	}
}

void	ft_stack(char *str, t_stack **stack)
{
	t_stack	*new;

	new = new_stack(str);
	if (!new)
		return ;
	stack_add_back(stack, new);
}
