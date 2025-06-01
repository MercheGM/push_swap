/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:58:22 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/01 18:19:12 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
 /* Each node has:
 *	- content: stack number
 *  - index:   current position at stack
 * 	- above_center:  node is above center of the stack
 *  - prev:    previous stack
 *  - next:    next stack
 */
typedef struct s_PS_list
{
	int					content;
	int					index;
	bool				above_center;
	int					cost;
	struct s_PS_list	*target;
	struct s_PS_list	*prev;
	struct s_PS_list	*next;
}					t_PS_list;

//main.c
//main function
void		push_swap(t_PS_list **stack_a, t_PS_list **stack_b);

//parsing.c
int			ft_check_save(char **argv, t_PS_list	**stack);
int			ft_parsing_numbers(char **argv, int numbers, t_PS_list	**stack);

//move_push.c
void		pa(t_PS_list **orig, t_PS_list **dest);
void		pb(t_PS_list **orig, t_PS_list **dest);
void		push_init(t_PS_list **stack_a, t_PS_list **stack_b);
//move_reverse_rotate.c
void		rra(t_PS_list **stack);
void		rrb(t_PS_list **stack);
void		rrr(t_PS_list **stack_a, t_PS_list **stack_b);

//move_rotate.c
void		ra(t_PS_list **stack);
void		rb(t_PS_list **stack);
void		rr(t_PS_list **stack_a, t_PS_list **stack_b);

//move_swap.c
void		sa(t_PS_list **stack);
void		sb(t_PS_list **stack);
void		ss(t_PS_list **stack_a, t_PS_list **stack_b);

//utils_stack.c
t_PS_list	*ps_lstnew(int newelement);
int			ps_lstsize(t_PS_list *lst);
void		ps_lstadd_bottom(t_PS_list **lst, t_PS_list *lnew);
void		ps_print_content(t_PS_list *stack);
void		ps_lstclear(t_PS_list **stack);
void		ps_updateindex (t_PS_list **stack);


void		ft_sort_two(t_PS_list **stack);
void		ft_sort_three(t_PS_list **stack);
void		ft_sort(t_PS_list **stack_a, t_PS_list **stack_b);
void		ft_find_target(t_PS_list **stack_a, t_PS_list **stack_b);
bool		ft_issorted(t_PS_list **stack);
t_PS_list	*ft_find_min(t_PS_list **stack_a);
void		ft_get_cost(t_PS_list **stack_a, t_PS_list **stack_b);
t_PS_list	*ft_find_cheapest(t_PS_list **stack);
void		ft_move(t_PS_list **stack_a, t_PS_list **stack_b);
t_PS_list	*ft_find_maximum_bottom(t_PS_list **stack, t_PS_list **max);
void		ft_sort_min(t_PS_list **stack);
#endif