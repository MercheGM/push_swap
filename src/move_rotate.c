/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:22:24 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/25 17:49:40 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_PS_list **stack, char name_stack)
{
	t_PS_list	*bottom;
	t_PS_list	*aux;

	aux = (*stack)->next;
	bottom = (*stack);
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->next = (*stack);
	(*stack)->prev = bottom;
	(*stack)->next = NULL;
	*stack = aux;
	ft_printf("rotating...\n");
	if (name_stack == 'A')
		ft_printf("ra\n");
	else if (name_stack == 'B')
		ft_printf("rb\n");
	else if (name_stack == 'R')
		ft_printf("rr\n");
}

void	ft_reverse_rotate(t_PS_list **stack, char name_stack)
{
	t_PS_list	*bottom;
	t_PS_list	*aux;

	bottom = (*stack);
	while (bottom->next != NULL)
	{
		aux = bottom;
		bottom = bottom->next;
	}
	bottom->prev = NULL;
	aux->next = NULL;
	bottom->next = (*stack);
	(*stack)->prev = bottom;
	(*stack) = bottom;
	ft_printf("reverse rotating...\n");
	if (name_stack == 'A')
		ft_printf("rra\n");
	else if (name_stack == 'B')
		ft_printf("rrb\n");
	else if (name_stack == 'R')
		ft_printf("rrr\n");
}
