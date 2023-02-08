/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case3_case5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:48 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 17:49:23 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_smallest_index(t_list *stack_a)
{
	int			min;
	t_list		*ptr;

	ptr = stack_a;
	min = ptr -> index;
	while (ptr != NULL)
	{
		if (ptr -> index < min)
			min = ptr -> index;
		ptr = ptr -> next;
	}
	free(ptr);
	return (min);
}

void	case3_utl(t_list **stack_a)
{
	swap_a(stack_a);
	rra(stack_a);
}

void	case3(t_list **stack_a)
{
	if (((*stack_a)-> data > (*stack_a)-> next -> data)
		&& ((*stack_a)-> data < (*stack_a)-> next -> next -> data)
		&& ((*stack_a)-> next -> data < (*stack_a)-> next -> next -> data))
		swap_a(stack_a);
	else if (((*stack_a)-> data > (*stack_a)-> next -> data)
		&& ((*stack_a)-> data > (*stack_a)-> next -> next -> data)
		&& ((*stack_a)-> next -> data > (*stack_a)-> next -> next -> data))
		case3_utl(stack_a);
	else if ((((*stack_a)-> data > (*stack_a)-> next -> data)
			&& ((*stack_a)-> data > (*stack_a)-> next -> next -> data)
			&& ((*stack_a)-> next -> data < (*stack_a)-> next -> next -> data)))
		ra(stack_a);
	else if ((((*stack_a)-> data < (*stack_a)-> next -> data)
			&& ((*stack_a)-> data < (*stack_a)-> next -> next -> data)
			&& ((*stack_a)-> next -> data > (*stack_a)-> next -> next -> data)))
	{
		swap_a(stack_a);
		ra(stack_a);
	}
	else if ((((*stack_a)->data < (*stack_a)-> next -> data)
			&& ((*stack_a)->data > (*stack_a)->next -> next -> data)
			&& ((*stack_a)->next -> data > (*stack_a)-> next -> next -> data)))
		rra(stack_a);
}

void	case5(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	min;

	min = check_smallest_index(*stack_a);
	index = searching_for_index(stack_a, min);
	while (lst_size(*stack_b) < 2)
	{
		while (searching_for_index(stack_a, min) != 0)
			a_rot(stack_a, index);
		if (searching_for_index(stack_a, min) == 0)
		{
			push_b(stack_b, stack_a);
			min++;
		}
	}
	case3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
