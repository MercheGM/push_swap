/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:14:19 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/25 18:51:31 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Takes the first element from stack orig and puts it first in stack dest. 
It does nothing if orig is empty.*/
void	ft_push(t_PS_list **orig, t_PS_list **dest)
{
	t_PS_list	*aux_orig;
	int			elem_orig;

	elem_orig = ps_lstsize(*orig);
	if (elem_orig > 0)
	{
		aux_orig = (*orig);
		(*orig) = (*orig)->next;
		if ((*orig) != NULL)
			(*orig)->prev = NULL;
		aux_orig->next = (*dest);
		aux_orig->prev = NULL;
		(*dest)->prev = aux_orig;
		(*dest) = aux_orig;
	}
}

/*Takes the first element from the stack b and puts it first in the stack
a. Does nothing if b is empty..*/
void	pa(t_PS_list **stack_a, t_PS_list **stack_b)
{
	ft_printf("pushing...\n");
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

/*Takes the first element from the stack a and puts it first in the stack
b. Does nothing if a is empty..*/
void	pb(t_PS_list **stack_b, t_PS_list **stack_a)
{
	ft_printf("pushing...\n");
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
