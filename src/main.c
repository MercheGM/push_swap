/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:01:08 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/22 19:06:14 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int	status;
	t_PS_list *stackA;
	
	status = 1;
	stackA = NULL;//(t_PS_list *)ft_calloc(1, sizeof(t_PS_list));
	if (argc >= 2)
	{
		//saved = ft_split_str(arg)
	
		//stackA = ft_save_argv(argv);
		status = ft_save_argv(argv, &stackA);
		if (!status)
			PS_print_content(stackA);
		else
			//ft_printf("Error\n");
			ft_putstr_fd("Error\n", STDERR_FILENO);
	}
	else
		ft_printf("incorrect arguments! \n");
	PS_lstclear(&stackA);

	return (status);
}