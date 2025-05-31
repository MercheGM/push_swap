/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:50:33 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/31 12:28:44 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the number is at the stack */
static int	check_duplicates(int number, t_PS_list **stack)
{
	t_PS_list	*aux;

	aux = *stack;
	while (aux)
	{
		if (number == aux->content)
			return (EXIT_FAILURE);
		aux = aux->next;
	}
	return (EXIT_SUCCESS);
}

/* Checks whether there is any letter at the string */
static bool	check_letters(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isalpha(str[i]))
			return (true);
	}
	return (false);
}

/*Checks inputs:
	- Double numbers
	- Letters
	- Only + or - signal
	- Over/Underflow
	- Duplicates.
Just in case the number is correct, then it creats a new node and
adds it to the bottom */
int	ft_parsing_numbers(char **argv, int elements, t_PS_list	**stack)
{
	int			i;
	t_PS_list	*stack_aux;
	long		number;

	i = -1;
	while (++i < elements)
	{
		if (ft_strchr(argv[i], '.') || check_letters(argv[i]) || \
			!ft_strncmp(argv[i], "+", 2) || !ft_strncmp(argv[i], "-", 2))
			return (EXIT_FAILURE);
		number = ft_atol(argv[i]);
		if (number <= INT_MAX && number > INT_MAX)
			return (EXIT_FAILURE);
		if (check_duplicates((int)number, stack))
		{
			ps_lstclear(stack);
			return (EXIT_FAILURE);
		}
		else
		{
			stack_aux = ps_lstnew(number);
			ps_lstadd_bottom(stack, stack_aux);
		}
	}
	ps_updateindex(stack);
	return (EXIT_SUCCESS);
}

/*Checks each element and saves them into the stack*/
int	ft_check_save(char **argv, t_PS_list	**stack)
{
	int		argc;
	char	**aux;
	int		status;

	argc = ft_count_elem((const void *const *)argv);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (EXIT_FAILURE);
		aux = ft_split(argv[1], ' ');
		status = ft_parsing_numbers(aux, ft_count_strs(aux), stack);
		aux = ft_memfree_str(aux);
	}
	else
		status = ft_parsing_numbers(++argv, argc - 1, stack);
	if (status)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
