/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:16:56 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:16:58 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(t_list **a, t_list **b, t_stack **stack, char **str)
{
	free(str);
	ft_dlstclear(a, NULL);
	ft_dlstclear(b, NULL);
	stack_clear(stack);
}

int	print_err(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

int	ft_errors(char **strs, t_list **a, t_list **b, t_stack **stack)
{
	print_err("Error\n");
	ft_free_all(a, b, stack, strs);
	return (0);
}
