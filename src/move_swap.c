/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:09:29 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/25 17:55:47 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_PS_list **stack, char name_stack)
{
	t_PS_list	*aux;

	ft_printf("swaping...\n");
	aux = (*stack)->next;
	aux->prev = NULL;
	(*stack)->next = aux->next;
	(*stack)->prev = aux;
	aux->next = *stack;
	(*stack) = aux;
	if (name_stack == 'A')
		ft_printf("sa\n");
	else if (name_stack == 'B')
		ft_printf("sb\n");
	else if (name_stack == 'S')
		ft_printf("ss\n");
}
