/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:50:33 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/07 14:56:58 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the number is at the stack */
static int	check_duplicates(int number, t_stack **stack)
{
	t_stack	*aux;

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
int	ft_parsing_numbers(char **argv, int elements, t_stack	**stack)
{
	int		i;
	t_stack	*stack_aux;
	long	number;

	i = -1;
	while (++i < elements)
	{
		if (ft_strchr(argv[i], '.') || check_letters(argv[i]) || \
			!ft_strncmp(argv[i], "+", 2) || !ft_strncmp(argv[i], "-", 2))
			return (EXIT_FAILURE);
		number = ft_atol(argv[i]);
		if (!(number >= INT_MIN && number <= INT_MAX))
			return (EXIT_FAILURE);
		if (check_duplicates((int)number, stack))
		{
			ps_clearstack(stack);
			return (EXIT_FAILURE);
		}
		else
		{
			stack_aux = ps_newstack(number);
			ps_addstack_bottom(stack, stack_aux);
		}
	}
	return (EXIT_SUCCESS);
}

/*Checks each element and saves them into the stack*/
int	ft_check_save(char **argv, t_stack	**stack)
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
	ps_updateindex(stack);
	return (EXIT_SUCCESS);
}
