/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:35:17 by souledla          #+#    #+#             */
/*   Updated: 2023/01/15 18:58:27 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void *create_node(int data)
{
	l_list *node = malloc(sizeof(l_list));
	node -> data = data;
	node ->next = NULL;
	return node;
}
void append_node(l_list **head, l_list *node)
{
	
	if (!*head)
		*head = node;
	l_list *current = *head;
	while ((*head) -> next != NULL)
		*head = (*head) -> next;
	(*head) -> next = node;
	node -> next = NULL;
	*head = current;
	//printf("%d", (*head)->next->next->data);
}
void get_node(l_list *head, int index)
{
	int counter = 0;
	l_list *current = head;
	while (head -> next != NULL)
	{
		if (counter == index)
		{
			printf("%d", head->data);
			break;
		}
		head = head->next;
		counter++;
	} 
	head = NULL;
}
int lst_size(l_list **head)
{
	l_list *current;
	current = *head;
	int counter; 
	counter = 0;
	while ((*head))
	{
		*head = (*head) -> next;
		counter++; 
	}
	*head = current;
	return counter;
	
}
