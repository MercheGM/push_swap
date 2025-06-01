/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:01:08 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/01 17:50:39 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			status;
	t_PS_list	*stack_a;
	t_PS_list	*stack_b;

	status = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		status = ft_check_save(argv, &stack_a);
		if (!status)
		{
			//ft_printf("Stack antes de ordenar:\n");
			//ps_print_content(stack_a);
			push_swap(&stack_a, &stack_b);
		}
		else
			ft_putstr_fd("Error\n", STDERR_FILENO);
	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
		//ft_printf("Stack despues de ordenar:\n<<<<<A>>>>>\n");
	//ps_print_content(stack_a);
	//ft_printf("<<<<<B>>>>\n");
	//ps_print_content(stack_b);
	ps_lstclear(&stack_a);
	return (status);
}
