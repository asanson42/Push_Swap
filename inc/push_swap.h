/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:56 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:14:58 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*previous;
	int				content;
	struct s_list	*next;
}			t_list;

typedef struct s_stack
{
	char			*str;
	struct s_stack	*next;
}			t_stack;

typedef struct s_data
{
	int		min;
	int		max;
	int		c_min;
	int		c_max;
	int		chunk;
}			t_data;

// FONCTIONS ERRORS
int		print_err(char *str);
int		ft_errors(char **strs, t_list **a, t_list **b, t_stack **stack);

// FONCTIONS PARSER
char	**ft_split_arg(char **argv);
int		count_num(char *arg);
int		check_double(char **str, int size);
int		check_str(char **str, int size);
int		global_check(char **str, int size);

// FONCTIONS PRINT STACK
int		ft_ss(t_stack *lst);
int		ft_rr(t_stack *lst);
int		ft_rrr(t_stack *lst);
void	ft_dlstprnt(t_stack *lst);

void	stack_clear(t_stack **satck);
void	ft_stack(char *str, t_stack **stack);

// FONCTIONS DBLIST
int		ft_dlstsize(t_list *dlst);
t_list	*ft_dlstnew(int content);
t_list	*ft_dlstlast(t_list *dlst);
void	ft_dlstadd_back(t_list **adlst, t_list *dnew);
void	ft_dlstadd_front(t_list **adlst, t_list *dnew);

void	ft_dlstdelone(t_list *dlst, void (*del)(int));
void	ft_dlstclear(t_list **dlst, void (*del)(int));
void	ft_dlstprintf(t_list *dlst);
int		ft_is_sort(t_list *dlst);

void	ft_init_lst(t_list **a, char **str, int size);
t_data	init_data(void);

// FONCTIONS OPE
void	ft_push_b(t_list **a, t_list **b, t_stack **stack);
void	ft_push_a(t_list **b, t_list **a, t_stack **stack);
void	ft_reverse_rra(t_list **a, t_stack **stack);
void	ft_reverse_rrb(t_list **b, t_stack **stack);
void	ft_reverse_rr(t_list **a, t_list **b, t_stack **stack);
void	ft_rotate_a(t_list *a, t_stack **stack);
void	ft_rotate_b(t_list *b, t_stack **stack);
void	ft_rotate_rr(t_list *a, t_list *b, t_stack **stack);
void	ft_swap_a(t_list *a, t_stack **stack);
void	ft_swap_b(t_list *b, t_stack **stack);
void	ft_swap_ss(t_list *a, t_list *b, t_stack **stack);

// FONCTIONS SORT

int		smallest(t_list *dlst);
int		biggest(t_list *dlst);

void	ft_threeb(t_list **b, t_stack **stack);
void	ft_three(t_list **a, int size, t_stack **stack);

void	ft_five(t_list **a, t_list **b, t_stack **stack, t_data *data);

int		chunk_min_five(int chunk, int min, int max);
int		chunk_max_five(int chunk, int min, int max);
int		chunk_min(int chunk, int min, int max);
int		chunk_max(int chunk, int min, int max);

int		ft_is_chunk(t_list *lst, int c_min, int c_max);
int		scan_next(t_list *lst, int c_min, int c_max);
int		scan_back(t_list *lst, int c_min, int c_max);
int		first_or_second(t_list *lst, int hold_first, int hold_second);
int		ft_middle(t_list *a, int hold);
void	rot_or_rev_a(t_list **a, int hold, t_stack **stack);
void	rot_or_rev_b(t_list **b, int hold, t_stack **stack);
int		fbefore_push(t_list **a, t_list **b, t_stack **stack, t_data *data);
int		before_push(t_list **a, t_list **b, t_stack **stack, t_data *data);

void	ft_hundred(t_list **a, t_list **b, t_stack **stack, t_data *data);
void	ft_fivehundred(t_list **a, t_list **b, t_stack **stack, t_data *data);

void	ft_free_all(t_list **a, t_list **b, t_stack **stack, char **str);

void	ft_global_sort(t_list **a, t_list **b, t_stack **stack, t_data *data);

#endif
