/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:50:33 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/19 20:02:05 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*char	**ft_parsing_string(char **argv)
{
	//char	**str_aux;
	//int		numbers;
	
	return(ft_split(argv[1], ' '));
	//ft_printf("str: %s\n", str_aux[0]);
	//numbers = ft_count_elem((const void *const *)str_aux);
	//ft_parsing_numbers(str_aux, numbers);
}*/

bool	check_letters(char *str)
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

int	ft_parsing_numbers(char **argv, int elements, t_PS_list	*stack)
{
	int	i;
	t_PS_list	*stack_aux;
	int	number;
	int cont;
	(void)cont;
	i = -1;
	//stack = (t_PS_list *)ft_calloc(1)
	while (++i < elements)
	{
		if (ft_strchr(argv[i], '.') || check_letters(argv[i]))
		{
			return (EXIT_FAILURE);
		}
		number = ft_atoi(argv[i]);
		if (number <= INT_MAX && number > INT_MAX)
			return (EXIT_FAILURE);
		//PENDING: detectar duplicados.

		//crear
		stack_aux = PS_lstnew(number);
		//añadir a la lista
		PS_lstadd_back(&stack, stack_aux);

		//printf("argv[%d]: %s || %d \n", i, argv[i], number);
		//number = ft_atoi(argv[i]);
	}
	return (EXIT_SUCCESS);
}

//t_PUSW_list	*ft_save_argv(char **argv)
int ft_save_argv(char **argv, t_PS_list	*stack)
{
	int	argc;
	char	**aux;
	int status;
	
	argc = ft_count_elem((const void* const* )argv);
	if (argc == 2) //significa que nos meten los datos como cadena de caracteres
	{
		aux = ft_split(argv[1], ' ');
		status = ft_parsing_numbers(aux, ft_count_strs(aux), stack);
	}
	else //nos meten los números de manera directa
	{
		status = ft_parsing_numbers(++argv, argc - 1, stack);
	}
	ft_printf("ft_save_argv: ..%d..\n", stack->content);

	if (status)
	{
		aux = ft_memfree_str(aux);
		return (EXIT_FAILURE);
	}
	ft_printf("ft_save_argv: ..%d..\n", stack->content);
	return (EXIT_SUCCESS);
}
