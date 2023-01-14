/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:43:01 by souledla          #+#    #+#             */
/*   Updated: 2023/01/12 18:36:13 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "push_swap.h"
int main()
{
	l_list *test = NULL;
	
	l_list *stack_b = create_node(4);
	l_list *head = create_node(1);
	l_list *new_node = create_node(2);
	l_list *new_node_2 = create_node(3);
	l_list *new_node_3 = create_node(4);
	append_node(&stack_b, head);
	append_node(&head, new_node);	
	append_node(&head, new_node_2);
	append_node(&head, new_node_3);
	printf("%d", lst_size(&head));

	// printf("%p \n \n", head);
	//ra(&head);
	//printf("%p \n \n", head);
	//rra(&head);
	//swap_a(&head);
	// push_a(head, stack_b);
	// while (head != NULL)
	// {
	// 	printf("%d \n", head->data);
	// 	head = head -> next;
	// }
	// printf(" \n \n %p", head);
	//get_node(head, 0);
	// l_list *case_3 = create_node(0);
	// append_node(&case_3, head);
	// while(head != NULL)
	// {
	// 	printf("%d", head -> data);
	// 	head = head -> next;
	// }
	 		
}