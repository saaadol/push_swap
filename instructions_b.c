/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:09:49 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 16:59:21 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sb\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!(*stack_b))
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)-> next;
	head -> next = (*stack_a);
	*stack_a = head;
	write(1, "pb\n", 3);
}

void	rb(t_list **stack_a)
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
	write(1, "rb\n", 3);
}

void	rrb(t_list **head)
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
	write(1, "rrb\n", 4);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_a) || !((*stack_a)->next)
		||!(*stack_b) || !((*stack_b)->next))
		return ;
	current = *stack_a;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	while (head->next != NULL)
		head = head -> next;
	head -> next = current;
	head->next->next = NULL;
	current = *stack_b;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	while (head->next != NULL)
		head = head -> next;
	head -> next = current;
	head->next->next = NULL;
	write(1, "rr\n", 3);
}
