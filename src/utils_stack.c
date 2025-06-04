/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:13:37 by mergarci          #+#    #+#             */
/*   Updated: 2025/06/04 18:49:40 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Creates a new node */
t_stack	*ps_newstack(int newelement)
{
	t_stack	*list;

	list = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = newelement;
	list->index = 0;
	list->above_center = false;
	list->cost = 0;
	list->target = NULL;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

/* Counts number of elements at the stack */
int	ps_sizestack(t_stack *lst)
{
	int		cont;
	t_stack	*aux;

	cont = 0;
	if (lst != NULL)
	{
		aux = lst;
		while (aux)
		{
			aux = aux->next;
			cont++;
		}
	}
	return (cont);
}

/* Adds the new node at the bottom*/
void	ps_addstack_bottom(t_stack **lst, t_stack *lnew)
{
	t_stack	*bottom;

	if (*lst == NULL)
	{
		*lst = lnew;
		return ;
	}
	bottom = *lst;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->next = lnew;
	lnew->prev = bottom;
}

/* Frees memory of the stack */
void	ps_clearstack(t_stack **stack)
{
	t_stack	*aux;

	if (stack)
	{
		while (*stack != NULL)
		{
			aux = (*stack)->next;
			free(*stack);
			*stack = aux;
		}
	}
}

void	ps_updateindex(t_stack **stack)
{
	int		i;
	t_stack	*aux;
	int		center;

	aux = *stack;
	center = ps_sizestack(*stack) / 2;
	i = 0;
	while (aux)
	{
		if (i <= center)
			aux->above_center = true;
		else
			aux->above_center = false;
		aux->index = i++;
		aux->cost = 0;
		aux->target = NULL;
		aux = aux->next;
	}
}
