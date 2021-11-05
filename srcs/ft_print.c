/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:35 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:17:36 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ss(t_stack *dlst)
{
	t_stack	*dlst2;
	size_t	i;

	dlst2 = dlst->next;
	i = ft_strlen(dlst->str);
	if (ft_strncmp(dlst->str, "sa", i) == 0
		&& ft_strncmp(dlst2->str, "sb", i) == 0)
		return (1);
	if (ft_strncmp(dlst->str, "sb", i) == 0
		&& ft_strncmp(dlst2->str, "sa", i) == 0)
		return (1);
	return (0);
}

int	ft_rr(t_stack *dlst)
{
	t_stack	*dlst2;
	size_t	i;

	dlst2 = dlst->next;
	i = ft_strlen(dlst->str);
	if (ft_strncmp(dlst->str, "ra", i) == 0
		&& ft_strncmp(dlst2->str, "rb", i) == 0)
		return (1);
	if (ft_strncmp(dlst->str, "rb", i) == 0
		&& ft_strncmp(dlst2->str, "ra", i) == 0)
		return (1);
	return (0);
}

int	ft_rrr(t_stack *dlst)
{
	t_stack	*dlst2;
	size_t	i;

	dlst2 = dlst->next;
	i = ft_strlen(dlst->str);
	if (ft_strncmp(dlst->str, "rra", i) == 0
		&& ft_strncmp(dlst2->str, "rrb", i) == 0)
		return (1);
	if (ft_strncmp(dlst->str, "rrb", i) == 0
		&& ft_strncmp(dlst2->str, "rra", i) == 0)
		return (1);
	return (0);
}

void	ft_dlstprnt(t_stack *dlst)
{
	int	n;

	if (!dlst)
		return ;
	while (dlst && dlst->next)
	{
		n = 1;
		if (ft_ss(dlst) == 1)
			printf("ss\n");
		else if (ft_rr(dlst) == 1)
			printf("rr\n");
		else if (ft_rrr(dlst) == 1)
			printf("rrr\n");
		else
		{
			n = 0;
			printf("%s\n", dlst->str);
		}
		dlst = dlst->next;
		if (n == 1)
			dlst = dlst->next;
	}
	if (dlst->next == NULL)
		printf("%s\n", dlst->str);
}
