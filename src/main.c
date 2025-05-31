/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:01:08 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/31 21:38:16 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			status;
	t_PS_list	*stack_a;
	t_PS_list	*stack_b;
	//char		**aux;

	status = 1;
	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (argc >= 2)
	{
		status = ft_check_save(argv, &stack_a);
		if (!status)
			ps_print_content(stack_a);
		else
			ft_putstr_fd("Error\n", STDERR_FILENO);
	}
	else
		ft_printf("incorrect arguments! \n");
	ft_printf("Stack antes de ordenar:\n");
	ps_print_content(stack_a);
	push_swap(&stack_a, &stack_b);
	ft_printf("Stack despues de ordenar:\n<<<<<A>>>>>\n");
	ps_print_content(stack_a);
	ft_printf("<<<<<B>>>>\n");
	ps_print_content(stack_b);
	ps_lstclear(&stack_a);
	//ps_lstclear(&stack_b);
	//aux = ft_memfree_str(aux);
	return (status);
}


void	push_swap(t_PS_list **stack_a, t_PS_list **stack_b)
{
	if (ps_lstsize(*stack_a) == 1)
		return ;
	if (ps_lstsize(*stack_a) == 2)
		ft_sort_two(stack_a);
	else if (ps_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
		ft_sort(stack_a, stack_b);
}