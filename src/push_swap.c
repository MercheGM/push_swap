/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:48:34 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/07 14:59:15 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Decide which algorithm to apply */
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_issorted(stack_a))
	{
		if (ps_sizestack(*stack_a) == 1)
			return ;
		if (ps_sizestack(*stack_a) == 2)
			ft_sort_two(stack_a);
		else if (ps_sizestack(*stack_a) == 3)
			ft_sort_three(stack_a);
		else
			ft_sort(stack_a, stack_b);
	}
}

/* Algorithm for sorting a stack of 2 elements*/
void	ft_sort_two(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
	ps_updateindex(stack);
}

/* Algorithm for sorting a stack of 3 elements */
void	ft_sort_three(t_stack **stack)
{
	t_stack	*max;
	t_stack	*bottom;

	while (!ft_issorted(stack))
	{
		bottom = ft_find_maximum_bottom(stack, &max);
		if ((*stack)->content == max->content)
			ra(stack);
		else if ((bottom->content == max->content) && \
			((*stack)->content > (*stack)->next->content))
			sa(stack);
		else if ((*stack)->next->content == max->content)
		{
			if ((*stack)->content > bottom->content)
				rra(stack);
			else
				ra(stack);
		}
	}
	ps_updateindex(stack);
}

/* Algorithm for sorting a stack of N elements */
void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ps_sizestack(*stack_a);
	push_init(stack_a, stack_b);
	ft_sort_three(stack_a);
	while ((size != ps_sizestack(*stack_a)) && ps_sizestack(*stack_b) != 0)
	{
		ps_updateindex (stack_a);
		ps_updateindex (stack_b);
		ft_find_target(stack_a, stack_b);
		ft_get_cost(stack_a, stack_b);
		ft_move(stack_a, stack_b);
	}
	if (!ft_issorted(stack_a))
		ft_sort_min(stack_a);
}
