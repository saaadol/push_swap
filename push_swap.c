/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:21:01 by souledla          #+#    #+#             */
/*   Updated: 2023/02/08 16:12:33 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_check(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current -> next)
	{
		if (current -> data > current -> next -> data)
			return (0);
		current = current -> next;
	}
	return (1);
}

int	join_util(char **strs, char *joined, int size, char c)
{
	int	tot_len;
	int	i;
	int	k;
	int	j;

	tot_len = 0;
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		tot_len = ft_strlen(strs[i]);
		while (j < tot_len)
			joined[k++] = strs[i][j++];
		if (i != size - 1)
			joined[k++] = c;
		i++;
	}
	return (k);
}

char	*ft_join(char **strs, int size, char c)
{
	int		i;
	int		tot_len;
	char	*joined;
	int		k;

	tot_len = 0;
	i = 0;
	while (i < size)
	{
		tot_len += ft_strlen(strs[i]) + 1;
		i++;
	}
	joined = (char *)malloc(tot_len + (size - 1) + 1);
	if (!joined)
		return (NULL);
	k = join_util(strs, joined, size, c);
	joined[k] = '\0';
	return (joined);
}

void	functions_exec(t_list **stack_a, t_list **stack_b)
{
	if (lst_size(*stack_a) == 3 || lst_size(*stack_a) == 5)
	{
		if (lst_size(*stack_a) == 3)
			case3(stack_a);
		else
			case5(stack_a, stack_b);
	}
	else
	{
		case100(stack_a, stack_b, lst_size(*stack_a));
		sorting(stack_a, stack_b);
	}	
}



int	main(int argc, char **argv)
{
	t_list	*stack_a;
	char	*joined;
	t_list	*stack_b;

	if (argc == 1)
		exit(1);
	if (argc == 2)
		print_error();
	stack_a = NULL;
	checking_str(argv);
	joined = ft_join(argv + 1, argc - 1, ' ');
	stack_a = filling_list(stack_a, joined);
	if (sorting_check(stack_a) == 1)
		exit(EXIT_FAILURE);
	checking_double(stack_a);
	free (joined);
	stack_b = NULL;
	committing_index(stack_a);
	functions_exec(&stack_a, &stack_b);
}
