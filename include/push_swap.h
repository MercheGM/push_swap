/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:58:22 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/25 18:50:11 by mergarci         ###   ########.fr       */
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

typedef struct s_PS_list
{
	int					content;
	int					index;
	struct s_PS_list	*next;
	struct s_PS_list	*prev;
}					t_PS_list;

//main.c
//main function

//parsing.c
int			ft_check_save(char **argv, t_PS_list	**stack);
int			ft_parsing_numbers(char **argv, int numbers, t_PS_list	**stack);

//move_push.c
void		pa(t_PS_list **stack_a, t_PS_list **stack_b);
void		pb(t_PS_list **stack_b, t_PS_list **stack_a);

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
void		ss(t_PS_list **stack);


//utils_stack.c
t_PS_list	*ps_lstnew(int newelement);
int			ps_lstsize(t_PS_list *lst);
void		ps_lstadd_bottom(t_PS_list **lst, t_PS_list *lnew);
void		ps_print_content(t_PS_list *stack);
void		ps_lstclear(t_PS_list **stack);

char		**ft_split_spaces(char const *s);
#endif