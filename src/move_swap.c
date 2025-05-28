/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:09:29 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/28 19:36:15 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swaps the first two elements of the stack. 
Do nothing if there are one or fewer elements.*/
void	ft_swap(t_PS_list **stack)
{
	t_PS_list	*aux;

	if (ps_lstsize(*stack) >= 2)
	{
		aux = (*stack)->next;
		aux->prev = NULL;
		(*stack)->next = aux->next;
		(*stack)->prev = aux;
		aux->next = *stack;
		(*stack) = aux;
	}
}

/*Swaps the first two elements of the stack A. 
Do nothing if there are one or fewer elements.*/
void	sa(t_PS_list **stack)
{
	ft_swap(stack);
	ft_printf("sa\n");
}

/*Swaps the first two elements of the stack B. 
Do nothing if there are one or fewer elements.*/
void	sb(t_PS_list **stack)
{
	ft_swap(stack);
	ft_printf("sb\n");
}

/*Swaps the first two elements of the stacks A and B. 
Do nothing if there are one or fewer elements.*/
void	ss(t_PS_list **stack_a, t_PS_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
