/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:01:08 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/18 18:55:10 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int	status;
	t_PUSW_list *stackA;
	
	status = 1;
	(void)stackA;
	if (argc >= 2)
	{
		//stackA = ft_save_argv(argv);
		ft_save_argv(argv);
		status = 0;
	}
	else
		ft_printf("incorrect arguments! \n");
	return (status);
}