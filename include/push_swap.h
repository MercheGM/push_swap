/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:58:22 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/25 17:54:37 by mergarci         ###   ########.fr       */
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

//move_swap.c
void		ft_swap(t_PS_list **stack, char name_stack);
//move_rotate.c
void		ft_rotate(t_PS_list **stack, char name_stack);
void		ft_reverse_rotate(t_PS_list **stack, char name_stack);

//move_push.c
void		ft_push(t_PS_list **orig, t_PS_list **dest, char name_stack);

//utils_stack.c
t_PS_list	*ps_lstnew(int newelement);
int			ps_lstsize(t_PS_list *lst);
void		ps_lstadd_bottom(t_PS_list **lst, t_PS_list *lnew);
void		ps_print_content(t_PS_list *stack);
void		ps_lstclear(t_PS_list **stack);

char		**ft_split_spaces(char const *s);
#endif