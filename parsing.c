/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:37:22 by souledla          #+#    #+#             */
/*   Updated: 2023/02/08 16:12:13 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	skip_space(char *nptr, int *i)
{
	while (nptr[*i] == 32 || (nptr[*i] >= 9 && nptr[*i] <= 13))
		(*i)++;
}

static void	result_sign(char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign *= -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

int	ft_atoi(char *nptr)
{
	int		x[2];
	int		temp;
	long	result;

	x[0] = 0;
	x[1] = 1;
	result = 0;
	skip_space(nptr, &x[0]);
	result_sign(nptr, &x[0], &x[1]);
	while (nptr[x[0]] >= 48 && nptr[x[0]] <= 57)
	{
		temp = result;
		result = result * 10;
		if (result / 10 != temp && result)
			print_error();
		result += nptr[x[0]] - 48;
		if (result * x[1] > INT_MAX || result * x[1] < INT_MIN)
			print_error();
		x[0]++;
	}
	return (result * x[1]);
}

void	checking_double(t_list *stack_b)
{
	t_list	*current;
	t_list	*current1;

	current = stack_b;
	while (current -> next != NULL)
	{
		current1 = current -> next;
		while (current1 != NULL)
		{
			if (current -> data == current1 -> data)
				print_error();
		current1 = current1 -> next;
		}
		current = current -> next;
	}
}

void	filling_util(t_list **head, t_list **temp, char **split)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (split[i])
	{
		number = ft_atoi(split[i]);
		if (!*temp)
		{
			(*head) = malloc(sizeof(t_list));
			(*head)->data = number;
			(*head)->next = NULL;
			(*temp) = *head;
		}
		else
		{
			(*temp)->next = malloc(sizeof(t_list));
			(*temp)->next->data = number;
			(*temp)->next->next = NULL;
			(*temp) = (*temp)->next;
		}
		i++;
	}
}
