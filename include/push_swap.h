/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:58:22 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/18 18:39:11 by mergarci         ###   ########.fr       */
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


typedef struct s_PUSH_list
{
	int				content;
	int				index;
	struct s_PUSH_list	*next;
}					t_PUSW_list;

//main.c
//main function

//parsing.c
void ft_save_argv(char **argv);
//t_PUSW_list	*ft_save_argv(char **argv);
void        ft_parsing_string(char **argv);
void        ft_parsing_numbers(char **argv, int numbers);

#endif