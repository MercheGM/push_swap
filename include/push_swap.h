/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:58:22 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/19 20:02:26 by mergarci         ###   ########.fr       */
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
	int				content;
	int				index;
	struct s_PS_list	*next;
}					t_PS_list;

//main.c
//main function

//parsing.c
int  ft_save_argv(char **argv, t_PS_list	*stack);
//t_PUSW_list	*ft_save_argv(char **argv);
//char	**ft_parsing_string(char **argv);
int		ft_parsing_numbers(char **argv, int numbers, t_PS_list	*stack);

//parsing_duplicates.c
bool check_duplicate(int number, t_PS_list **stack);

//utils_stack.c
t_PS_list	*PS_lstnew(int new_element);
int	PS_lstsize(t_PS_list *lst);
void	PS_lstadd_back(t_PS_list **lst, t_PS_list *lnew);


#endif