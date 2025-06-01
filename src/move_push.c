/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:14:19 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/01 18:08:30 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Takes the first element from stack orig and puts it first in stack dest. 
It does nothing if orig is empty.*/
void	ft_push(t_PS_list **orig, t_PS_list **dest)
{
	t_PS_list	*aux_orig;

	if (ps_lstsize(*orig) > 0)
	{
		aux_orig = (*orig)->next;
		if (ps_lstsize(*dest) == 0)
			(*orig)->next = NULL;
		else
		{
			(*orig)->next = *dest;
			(*dest)->prev = *orig;
		}
		*dest = *orig;
		*orig = aux_orig;
	}
}

/*Takes the first element from the stack b and puts it first in the stack
a. Does nothing if b is empty..*/
void	pa(t_PS_list **orig, t_PS_list **dest)
{
	ft_push(orig, dest);
	ft_printf("pa\n");
}

/*Takes the first element from the stack a and puts it first in the stack
b. Does nothing if a is empty..*/
void	pb(t_PS_list **orig, t_PS_list **dest)
{
	ft_push(orig, dest);
	ft_printf("pb\n");
}

void	push_init(t_PS_list **stack_a, t_PS_list **stack_b)
{
	int	size_a;

	size_a = ps_lstsize(*stack_a);
	while (size_a > 3)
	{
		pb(stack_a, stack_b);
		size_a--;
	}
	ps_updateindex(stack_a);
	ps_updateindex(stack_b);
}
