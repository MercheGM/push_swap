/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:28:33 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/28 20:02:07 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_PS_list	*ft_find_maximum_bottom(t_PS_list **stack, t_PS_list **max)
{
	t_PS_list	*aux;

	*max = *stack;
	aux = *stack;
	while (aux->next)
	{
		if (aux->content > (*max)->content)
			*max = aux;
		aux = aux->next;
	}
	if (aux->content > (*max)->content)
		*max = aux;
	return (aux);
}

void	ft_sort_three(t_PS_list **stack)
{
	t_PS_list	*max;
	t_PS_list	*bottom;

	while (!ft_issorted(stack))
	{
		bottom = ft_find_maximum_bottom(stack, &max);
		if ((*stack)->content == max->content)
			ra(stack);
		else if ((bottom->content == max->content) && \
			((*stack)->content > (*stack)->next->content))
			sa(stack);
		if ((*stack)->next->content == max->content)
		{
			if ((*stack)->content > bottom->content)
				rra(stack);
			else
				ra(stack);
		}
	}
}

/** Checks if stack is sorted */
bool	ft_issorted(t_PS_list **stack)
{
	bool		issorted;
	t_PS_list	*aux;

	aux = *stack;
	issorted = false;
	while (aux->next != NULL)
	{
		if (aux->content < aux->next->content)
			issorted = true;
		else
		{
			issorted = false;
			break ;
		}
		aux = aux->next;
	}
	return (issorted);
}
