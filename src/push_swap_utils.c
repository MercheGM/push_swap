/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:28:33 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/04 19:01:55 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if stack is sorted */
bool	ft_issorted(t_stack **stack)
{
	bool	issorted;
	t_stack	*aux;

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

/*Get the cost of moving each node from stack b to its target at stack a*/
void	ft_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;

	b = *stack_b;
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_center))
			b->cost = ps_sizestack(*stack_b) - (b->index);
		if (b->target->above_center)
			b->cost += b->target->index;
		else
			b->cost += ps_sizestack(*stack_a) - (b->target->index);
		b = b->next;
	}
}

/* Finish the rotation of the stacks */
static void	ft_finish_rotation(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_center)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_center)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

/*Move both stacks depending on the cheapest node at stack b*/
void	ft_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = ft_find_cheapest(stack_b);
	if (cheapest->above_center && cheapest->target->above_center)
	{
		while (*stack_a != cheapest->target && *stack_b != cheapest)
			rr(stack_a, stack_b);
	}
	else if (!(cheapest->above_center) && !(cheapest->target->above_center))
	{
		while (*stack_a != cheapest->target && *stack_b != cheapest)
			rrr(stack_a, stack_b);
	}
	ft_finish_rotation(stack_b, cheapest, 'b');
	ft_finish_rotation(stack_a, cheapest->target, 'a');
	pa(stack_b, stack_a);
}

/*Sort the stack depending on the minimum content*/
void	ft_sort_min(t_stack **stack)
{
	t_stack	*min;

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
