/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:28:33 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/01 18:20:34 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_get_cost(t_PS_list **stack_a, t_PS_list **stack_b)
{
	t_PS_list	*b;

	b = *stack_b;
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_center))
			b->cost = ps_lstsize(*stack_b) - (b->index);
		if (b->target->above_center)
			b->cost += b->target->index;
		else
			b->cost += ps_lstsize(*stack_a) - (b->target->index);
		b = b->next;
	}
}

void	ft_move(t_PS_list **stack_a, t_PS_list **stack_b)
{
	t_PS_list	*cheapest;
	int			cost_var;

	cheapest = ft_find_cheapest(stack_b);
	cost_var = cheapest->cost;
	if (cheapest->index > 0 && cheapest->above_center)
	{
		while (cheapest->index--)
			rb(stack_b);
	}
	while (cost_var--)
	{
		if (cheapest->above_center && !cheapest->target->above_center)
			rra(stack_a);
		else if (!cheapest->above_center && !cheapest->target->above_center)
			rrr(stack_a, stack_b);
		else if (cheapest->target->index != 0)
		{
			while ((*stack_a)->content != cheapest->target->content)
				ra(stack_a);
		}
	}
	pa(stack_b, stack_a);
}

void	ft_sort_min(t_PS_list **stack)
{
	t_PS_list	*min;

	min = ft_find_min(stack);
	if (min->above_center)
	{
		while ((*stack)->content != min->content)
			ra(stack);
	}
	else
	{
		while ((*stack)->content != min->content)
			rra(stack);
	}
}
