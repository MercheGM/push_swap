/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:50:33 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/18 19:09:32 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing_string(char **argv)
{
	char	**str_aux;
	int		numbers;
	
	str_aux = ft_split(argv[1], ' ');
	//ft_printf("str: %s\n", str_aux[0]);
	numbers = ft_count_elem((const void *const *)str_aux);
	ft_parsing_numbers(str_aux, numbers);
}

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

void	ft_parsing_numbers(char **argv, int elements)
{
	int			i;
	//t_PUSW_list	*stack;
	int			number;

	i = -1;
	while (++i < elements)
	{
		if (ft_strchr(argv[i], '.') || check_letters(argv[i]))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		number = ft_atoi(argv[i]);
		printf("argv[%d]: %s || %d \n", i, argv[i], number);
		//number = ft_atoi(argv[i]);
	}
}

//t_PUSW_list	*ft_save_argv(char **argv)
void ft_save_argv(char **argv)
{
	int	argc;

	argc = ft_count_elem((const void* const* )argv);
	if (argc == 2) //significa que nos meten los datos como cadena de caracteres
	{
		ft_parsing_string(argv);
	}
	else //nos meten los números de manera directa
	{
		ft_parsing_numbers(++argv, argc - 1);
	}
	//ft_printf("%s\n", argv[0]);
}