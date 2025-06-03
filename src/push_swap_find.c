/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:52:05 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/03 19:57:15 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find minimum stack content */
t_PS_list	*ft_find_min(t_PS_list **stack_a)
{
	t_PS_list	*aux;
	t_PS_list	*min;

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
void	ft_find_target(t_PS_list **stack_a, t_PS_list **stack_b)
{
	t_PS_list	*b;
	t_PS_list	*a;
	t_PS_list	*target_stack;
	int			max;

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
t_PS_list	*ft_find_cheapest(t_PS_list **stack)
{
	t_PS_list	*aux;
	t_PS_list	*cheapest;

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
