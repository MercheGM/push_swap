/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:01:08 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/07 14:58:47 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		status;
	t_stack	*stack_a;
	t_stack	*stack_b;

	status = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		status = ft_check_save(argv, &stack_a);
		if (!status)
			push_swap(&stack_a, &stack_b);
		else
			ft_putstr_fd("Error\n", STDERR_FILENO);
		if (stack_a)
			ps_clearstack(&stack_a);
	}
	return (status);
}
