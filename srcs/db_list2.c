/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:16:44 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:16:45 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstdelone(t_list *dlst, void (*del)(int))
{
	if (dlst != NULL)
	{
		if (del && dlst->content)
			(del)(dlst->content);
		free(dlst);
		dlst = NULL;
	}
}

void	ft_dlstclear(t_list **dlst, void (*del)(int))
{
	t_list	*current;
	t_list	*next;

	if (*dlst)
	{
		current = *dlst;
		while (current != NULL)
		{
			next = current->next;
			ft_dlstdelone(current, (del));
			current = next;
		}
		*dlst = NULL;
	}
}

void	ft_dlstprintf(t_list *dlst)
{
	if (!dlst)
		printf("liste vide\n");
	while (dlst)
	{
		if (!dlst->content)
			printf("[NULL] ");
		else
			printf("[%d] ", dlst->content);
		dlst = dlst->next;
	}
	printf("\n");
	return ;
}

int	ft_is_sort(t_list *dlst)
{
	t_list	*last;

	last = ft_dlstlast(dlst);
	while (dlst != last)
	{
		if (dlst->content < dlst->next->content)
			dlst = dlst->next;
		else
			return (0);
	}
	return (1);
}
