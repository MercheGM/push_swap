/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:13:37 by mergarci          #+#    #+#             */
/*   Updated: 2025/05/20 19:51:42 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_PS_list	*PS_lstnew(int new_element)
{
	t_PS_list	*list;

	list = (t_PS_list *)ft_calloc(1, sizeof(t_PS_list));
	if (!list)
		return (NULL);
	list->content = new_element;
	list->index = 0;
	list->next = NULL;
	return (list);
}

int	PS_lstsize(t_PS_list *lst)
{
	int		cont;
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

void	PS_lstadd_back(t_PS_list **lst, t_PS_list *lnew)
{
	t_PS_list	*aux;

	if (*lst == NULL)
	{
		//ft_printf("PS_lstadd_back: vamos a guardar: %d, %p, lnew: %p\n", lnew->content , *lst, *lnew);
		*lst = lnew;
		return ;
	}
	aux = *lst;
	while (aux->next != NULL)
	{
		//ft_printf("__recorriendo hasta llegar al final: %d\n", lnew->content);
		aux = aux->next;
	}
	aux->next = lnew;
}

void PS_print_content(t_PS_list *stack)
{
	t_PS_list *aux;
	
	aux = stack;
	ft_printf(">>>>IMPRIMIENDO<<<<\n");
	while (aux)
	{
		ft_printf("%d_", aux->content);
		aux = aux->next;
	}
	ft_printf("\n");
}

int check_duplicates(int number, t_PS_list **stack)
{
	t_PS_list	*aux;

	aux = *stack;
	while (aux)
	{
		if (number == aux->content)
			return (EXIT_FAILURE);
		aux = aux->next;
	}
	return (EXIT_SUCCESS);
}

void	PS_lstclear(t_PS_list **stack)
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
