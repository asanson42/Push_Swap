/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:19:14 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:19:16 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**new_str(char **argv, int argc)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	j = 0;
	str = malloc(sizeof(char *) * argc - 1);
	while (i < argc - 1 || argv[i] != NULL)
	{
		str[j] = argv[i];
		i++;
		j++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_stack	*s;
	t_data	data;
	char	**str;

	a = NULL;
	b = NULL;
	s = NULL;
	data = init_data();
	if (argc <= 1)
		return (0);
	str = new_str(argv, (argc));
	if (str == NULL || global_check(str, (argc - 1)))
		return (ft_errors(str, &a, &b, &s));
	ft_init_lst(&a, str, (argc - 1));
	if (ft_is_sort(a))
	{
		ft_free_all(&a, &b, &s, str);
		return (0);
	}
	ft_global_sort(&a, &b, &s, &data);
	ft_dlstprnt(s);
	ft_free_all(&a, &b, &s, str);
	return (0);
}
