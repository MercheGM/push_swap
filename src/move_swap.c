/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:09:29 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/31 13:59:57 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swaps the first two elements of the stack. 
Do nothing if there are one or fewer elements.*/
void	ft_swap(t_PS_list **stack)
{
	t_PS_list	*aux;
	t_PS_list	*third_element;

	third_element = NULL;
	if (ps_lstsize(*stack) >= 2)
	{
		if (ps_lstsize(*stack) >= 3)
			third_element = (*stack)->next->next;
		aux = (*stack)->next;
		aux->prev = NULL;
		(*stack)->next = third_element;
		(*stack)->prev = aux;
		if (third_element)
			third_element->prev = *stack;
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
