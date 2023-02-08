/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_list_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:09:04 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 17:49:06 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*filling_list(t_list *head, char *s)
{
	int		i;
	char	**split;
	t_list	*temp;

	split = ft_split(s, ' ');
	i = 0;
	temp = NULL;
	filling_util(&head, &temp, split);
	while (split[i])
		i++;
	if (i > 0 && !split[i - 1][0])
	{
		temp = head;
		while (temp->next->next)
			temp = temp->next;
		free(temp->next);
		temp->next = NULL;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	return (free(split), head);
}
