/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:52:05 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/04 18:43:05 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find minimum stack content */
t_stack	*ft_find_min(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*min;

	aux = *stack_a;
	min = *stack_a;
	while (aux)
	{
		if (aux->content < min->content)
			min = aux;
		aux = aux->next;
	}
	return (min);
}

/*Find the target of each node from stack b to stack a*/
void	ft_find_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*a;
	t_stack	*target_stack;
	int		max;

	b = *stack_b;
	while (b)
	{
		max = INT_MAX;
		a = *stack_a;
		while (a)
		{
			if (b->content < a->content && a->content < max)
			{
				max = a->content;
				target_stack = a;
			}
			a = a->next;
		}
		if (max == INT_MAX)
			b->target = ft_find_min(stack_a);
		else
			b->target = target_stack;
		b = b->next;
	}
}

/*Find the cheapest node*/
t_stack	*ft_find_cheapest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*cheapest;

	aux = *stack;
	cheapest = *stack;
	while (aux)
	{
		if (aux->cost < cheapest->cost)
			cheapest = aux;
		aux = aux->next;
	}
	return (cheapest);
}

/*Find the maximum stack and the bottom stack*/
t_stack	*ft_find_maximum_bottom(t_stack **stack, t_stack **max)
{
	t_stack	*aux;

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
