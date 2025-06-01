/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:48:34 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/01 18:21:02 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_PS_list **stack_a, t_PS_list **stack_b)
{
	if (ps_lstsize(*stack_a) == 1)
		return ;
	if (ps_lstsize(*stack_a) == 2)
		ft_sort_two(stack_a);
	else if (ps_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
		ft_sort(stack_a, stack_b);
}

void	ft_sort_two(t_PS_list **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
	ps_updateindex(stack);
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

void	ft_sort(t_PS_list **stack_a, t_PS_list **stack_b)
{
	int	total_size;

	total_size = ps_lstsize(*stack_a);
	push_init(stack_a, stack_b);
	ft_sort_three(stack_a);
	while ((total_size != ps_lstsize(*stack_a)) && ps_lstsize(*stack_b) != 0)
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
