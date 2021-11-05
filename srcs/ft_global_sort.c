/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:04 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:17:06 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_global_sort(t_list **a, t_list **b, t_stack **stack, t_data *data)
{
	int	lstsize;

	lstsize = ft_dlstsize(*a);
	if (lstsize > 1 && lstsize <= 3)
		ft_three(a, lstsize, stack);
	if (lstsize > 3 && lstsize <= 5)
		ft_five(a, b, stack, data);
	if (lstsize > 5 && lstsize <= 100)
		ft_hundred(a, b, stack, data);
	if (lstsize > 100)
		ft_fivehundred(a, b, stack, data);
}
