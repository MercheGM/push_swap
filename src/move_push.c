/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:14:19 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/25 17:59:07 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_PS_list **orig, t_PS_list **dest, char name_stack)
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
		ft_printf("pushing...\n");
		if (name_stack == 'A')
		{
			ft_printf("pa\n");
		}
		else if (name_stack == 'B')
		{
			ft_printf("pb\n");
		}
	}
}
