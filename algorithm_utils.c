/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:30:38 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 17:48:36 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_rot(t_list **stack_b, int pos)
{
	if (pos == -1)
		return ;
	if (pos < (lst_size(*stack_b) / 2))
		ra(stack_b);
	else
		rra(stack_b);
}

void	b_rotation(t_list **stack_b, int pos)
{
	if (pos == -1)
		return ;
	if (pos < (lst_size(*stack_b) / 2))
		rb(stack_b);
	else
		rrb(stack_b);
}

int	searching_for_index(t_list **stack_a, int indexx)
{
	t_list	*ptr;
	int		counter;
	int		position;
	int		flag;

	counter = 0;
	position = 0;
	flag = -1;
	ptr = *stack_a;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index == indexx)
		{
			position = counter;
			flag = 0;
		}
		counter++;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = ptr;
	if (flag == -1)
		return (flag);
	return (position);
}

int	check_biggest_index(t_list *stack_a)
{
	static int	i;
	int			max;
	t_list		*ptr;

	ptr = stack_a;
	i = 0;
	max = ptr -> index;
	while (ptr != NULL)
	{
		if (ptr -> index > max)
			max = ptr -> index;
		ptr = ptr -> next;
	}
	free(ptr);
	i++;
	return (max - i +1);
}
