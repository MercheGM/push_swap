/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:34:13 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/28 19:09:52 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Shifts all elements in the stack down one position, 
so that the last element becomes the first.*/
static void	ft_reverse_rotate(t_PS_list **stack)
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
}

/*Shifts all elements in the stack A down one position, 
so that the last element becomes the first.*/
void	rra(t_PS_list **stack)
{
	ft_reverse_rotate(stack);
	ft_printf("rra\n");
}

/*Shifts all elements in the stack B down one position, 
so that the last element becomes the first.*/
void	rrb(t_PS_list **stack)
{
	ft_printf("reverse rotating...\n");
	ft_reverse_rotate(stack);
	ft_printf("rrb\n");
}

/*Shifts all elements in the stacks A and B down one position, 
so that the last element becomes the first.*/
void	rrr(t_PS_list **stack_a, t_PS_list **stack_b)
{
	ft_printf("reverse rotating...\n");
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
