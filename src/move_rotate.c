/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:22:24 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/28 19:10:00 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Shifts all elements in the stack up one position, so that the 
first element becomes the last.*/
static void	ft_rotate(t_PS_list **stack)
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
}

/*Shifts all elements in the stack A up one position, so that the 
first element becomes the last.*/
void	ra(t_PS_list **stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

/*Shifts all elements in the stack B up one position, so that the 
first element becomes the last.*/
void	rb(t_PS_list **stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

/*Shifts all elements in the stack A up one position, so that the 
first element becomes the last.*/
void	rr(t_PS_list **stack_a, t_PS_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
