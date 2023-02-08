/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:32:19 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 17:33:17 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case100(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk;
	int	counter;

	chunk = 30;
	counter = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index < chunk)
		{
			push_b(stack_b, stack_a);
			counter++;
		}
		else if (counter == chunk)
		{
			if (size > 100)
				chunk += 30;
			else
				chunk += 15;
		}
		else
			a_rot(stack_a, searching_for_index(stack_a, (*stack_a)->index));
	}
}

void	sorting(t_list **stack_a, t_list **stack_b)
{
	int	position;
	int	max;
	int	flag;
	int	index;

	position = 0;
	max = check_biggest_index(*stack_b);
	flag = 0;
	index = searching_for_index(stack_b, max);
	while ((*stack_b) != NULL && index == searching_for_index(stack_b, max))
		index = util(stack_a, stack_b, &max, index);
	if ((*stack_b) == NULL && (*stack_a)-> data > (*stack_a)-> next -> data)
		swap_a(stack_a);
}

int	util(t_list **stack_a, t_list **stack_b, int *max, int index)
{
	if ((*stack_a) && (*stack_a)->next
		&& (*stack_a)-> data > (*stack_a)->next->data)
	{
		swap_a(stack_a);
		(*max)--;
		index = searching_for_index(stack_b, *max);
	}
	else if ((searching_for_index(stack_b, ((*max) - 1)) == 0))
	{
		push_a(stack_a, stack_b);
		index = searching_for_index(stack_b, (*max));
	}
	else if (index == 2 && (searching_for_index(stack_b, ((*max) - 1)) == 0))
	{
		push_a(stack_a, stack_b);
		(*max)--;
		ra(stack_b);
		push_a(stack_a, stack_b);
		(*max)--;
		swap_a(stack_a);
		index = searching_for_index(stack_b, *max);
	}
	index = util1(stack_a, stack_b, max, index);
	return (index);
}

int	util1(t_list **stack_a, t_list **stack_b, int *max, int index)
{
	if (index == 1 && (searching_for_index(stack_b, ((*max) - 1)) == 0))
	{
		swap_b(stack_b);
		index = searching_for_index(stack_b, (*max));
	}
	else if (searching_for_index(stack_b, (*max)) == 0)
	{
		push_a(stack_a, stack_b);
		(*max)--;
		index = searching_for_index(stack_b, (*max));
	}
	else
	{
		b_rotation(stack_b, index);
		index = searching_for_index(stack_b, (*max));
	}
	return (index);
}
