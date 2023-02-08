/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:37:47 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 17:49:37 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!(*stack_b))
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)-> next;
	head -> next = (*stack_a);
	*stack_a = head;
	write(1, "pa\n", 3);
}

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	current = *stack_a;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	while (head->next != NULL)
		head = head -> next;
	head -> next = current;
	head->next->next = NULL;
	write(1, "ra\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "ss\n", 3);
}

void	rra(t_list **head)
{
	t_list	*last;
	t_list	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *head;
	*head = last;
	write(1, "rra\n", 4);
}
