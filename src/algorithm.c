/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:28:33 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/27 22:54:08 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_PS_list **stack)
{
	if (!ft_issorted(stack))
	{
		
	}
}

bool ft_issorted(t_PS_list **stack)
{
	bool issorted;
	t_PS_list *aux;
	
	(void)stack;
	aux = *stack;
	issorted = false;
	while (aux->next != NULL)
	{
		if (aux->content < aux->next->content)
			issorted = true;
		else
		{
			issorted = false;
			break;
		}
			//return (false);
		aux = aux->next;
	}
	return (issorted);
}