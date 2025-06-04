/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:58:22 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/04 19:02:17 by mergarci         ###   ########.fr       */
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
*  - content: stack number
*  - index:   current position at stack
*  - above_center:  node is above center of the stack
*  - cost:    cost of moving each node from stack b to its target at stack a
*  - target:  target at stack a
*  - prev:    previous stack
*  - next:    next stack
*/
typedef struct s_stack
{
	int				content;
	int				index;
	bool			above_center;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

//main.c
//main function

//parsing.c
int		ft_check_save(char **argv, t_stack	**stack);
int		ft_parsing_numbers(char **argv, int numbers, t_stack	**stack);

//move_push.c
void	pa(t_stack **orig, t_stack **dest);
void	pb(t_stack **orig, t_stack **dest);
void	push_init(t_stack **stack_a, t_stack **stack_b);

//move_reverse_rotate.c
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//move_rotate.c
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

//move_swap.c
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

//utils_stack.c
t_stack	*ps_newstack(int newelement);
int		ps_sizestack(t_stack *lst);
void	ps_addstack_bottom(t_stack **lst, t_stack *lnew);
void	ps_clearstack(t_stack **stack);
void	ps_updateindex(t_stack **stack);

//push_swap.c
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_two(t_stack **stack);
void	ft_sort_three(t_stack **stack);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);

//push_swap_find.c
t_stack	*ft_find_min(t_stack **stack_a);
void	ft_find_target(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_find_cheapest(t_stack **stack);
t_stack	*ft_find_maximum_bottom(t_stack **stack, t_stack **max);

//push_swap_utils.c
bool	ft_issorted(t_stack **stack);
void	ft_get_cost(t_stack **stack_a, t_stack **stack_b);
void	ft_move(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_min(t_stack **stack);

#endif