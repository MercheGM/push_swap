/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:13:37 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/31 12:31:35 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Creates a new node */
t_PS_list	*ps_lstnew(int newelement)
{
	t_PS_list	*list;

	list = (t_PS_list *)ft_calloc(1, sizeof(t_PS_list));
	if (!list)
		return (NULL);
	list->content = newelement;
	list->index = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

/* Counts number of elements at the stack */
int	ps_lstsize(t_PS_list *lst)
{
	int			cont;
	t_PS_list	*aux;

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
void	ps_lstadd_bottom(t_PS_list **lst, t_PS_list *lnew)
{
	t_PS_list	*bottom;

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

/* Prints the stack*/
void	ps_print_content(t_PS_list *stack)
{
	t_PS_list	*aux;

	aux = stack;
	//ft_printf(">>>>IMPRIMIENDO<<<<\n");
	while (aux)
	{
		ft_printf("Nodo: %d, content: %d\n", aux->index, aux->content);
		//ft_printf("%d_", aux->content);
		aux = aux->next;
	}
	ft_printf("\n");
}

/* Frees memory of the stack */
void	ps_lstclear(t_PS_list **stack)
{
	t_PS_list	*aux;

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

void ps_updateindex (t_PS_list **stack)
{
	int	i;
	t_PS_list *aux;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux->index = i++;
		aux = aux->next;
	}
}