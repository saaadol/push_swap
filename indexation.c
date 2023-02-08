/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:33:57 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 16:59:21 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	counting_index(t_list *stack_a, int x, int *index)
{
	int	counter;

	counter = 0;
	while (stack_a != NULL)
	{
		if (x > stack_a->data)
			counter++;
		stack_a = stack_a->next;
	}
	*index = counter;
}

void	committing_index(t_list *stack_a)
{
	int		i;
	int		j;
	t_list	*temp;
	t_list	*head;

	head = stack_a;
	while (stack_a)
	{
		i = 0;
		j = stack_a -> data;
		temp = head;
		while (temp)
		{
			if (temp -> data < j)
				i++;
			temp = temp -> next;
		}
		stack_a -> index = i;
		stack_a = stack_a ->next;
	}
}
