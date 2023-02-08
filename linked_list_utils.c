/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:35:17 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 16:59:21 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *head)
{
	int		counter;
	t_list	*current;

	if (head == NULL)
		return (0);
	current = head;
	counter = 0;
	while (current)
	{
		current = current -> next;
		counter++;
	}
	return (counter);
}
