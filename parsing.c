/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:37:22 by souledla          #+#    #+#             */
/*   Updated: 2023/02/05 04:51:34 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_isdigit(int c)
{

		if (c >= 48 && c <= 57)
			return (1);
		return (0);
	
}
int	ft_isdigit2(char  *str)
{
	int i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] == '-'))
			i++;
		else
			return (0);
		
	}
	return (1);
	
}
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
       i++;
    }
    return i;  
}
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
int ft_atoi(char *nptr)
{
    int x[2];
    long long result;
    int temp;

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
        {
            printf("Error b\n");
            exit(EXIT_FAILURE);
        }
        result += nptr[x[0]] - 48;
        if (result * x[1] >= INT_MAX || result * x[1] <= INT_MIN)
        {
            printf("Error c\n");
            exit(EXIT_FAILURE);
        }
        x[0]++;
    }
    return (result * x[1]);
}


void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	if (n == 0)
		return ;
	temp = (char *) s;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
void checking_double(l_list *stack_b)
{
	l_list *current = stack_b;
	l_list *current1;
	while(current -> next != NULL)
	{
		current1 = current -> next;
		while(current1 != NULL)
		{
			if (current -> data == current1 -> data)
			{
				printf("Error \n");
				exit(EXIT_FAILURE);
			}
		current1 = current1 -> next;	
		}
		current = current -> next;
	}
	
}
/*
l_list *filling_list(l_list *head, int ac, char **av)
{
    int i = 1;
    l_list *temp = NULL;
    int number = 0;

    while (i < ac)
    {
        number = ft_atoi(av[i]);
        if (!temp)
        {
            head = malloc(sizeof(l_list));
            head->data = number;
            head->next = NULL;
            temp = head;
        }
        else
        {
            temp->next = malloc(sizeof(l_list));
            temp->next->data = number;
            temp->next->next = NULL;
            temp = temp->next;
        }
        i++;
    }
    return head;
}
*/
// char **ft_split(char *s, char c)
// {
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int count = 0;
//     char **str;
//     while (s[i] != '\0')
//     {
//         if (s[i] == c)
//             count++;
//         i++;
//     }
//     count++;
//     str = (char**)malloc(sizeof(char*) * (count + 1));
//     i = 0;
//     while (s[i] != '\0')
//     {
//         if (s[i] == c || s[i + 1] == '\0')
//         {
//             str[k] = (char*)malloc(sizeof(char) * (j + 1));
//             j = 0;
//             k++;
//         }
//         else
//         {
//             j++;
//         }
//         i++;
//     }
//     if (k == count - 1)
//     {
//         str[k] = (char*)malloc(sizeof(char) * (j + 1));
//         str[k][j] = '\0';
//         k++;
//     }
//     str[k] = NULL;
//     k = 0;
//     j = 0;
//     i = 0;
//     while (s[i] != '\0')
//     {
//         if (s[i] == c || s[i + 1] == '\0')
//         {
//             str[k][j] = '\0';
//             j = 0;
//             k++;
//         }
//         else
//         {
//             str[k][j] = s[i];
//             j++;
//         }
//         i++;
//     }
//     return (str);
// }


l_list *filling_list(l_list *head, char *s)
{
    char **split = ft_split(s, ' ');
    int i = 0;
    int number = 0;
    l_list *temp = NULL;

    while (split[i])
    {	
        number = ft_atoi(split[i]);
        if (!temp)
        {
            head = malloc(sizeof(l_list));
            head->data = number;
            head->next = NULL;
            temp = head;
        }
        else
        {
            temp->next = malloc(sizeof(l_list));
            temp->next->data = number;
            temp->next->next = NULL;
            temp = temp->next;
        }
        i++;
    }

    // Check if last split value is not empty
    if (i > 0 && !split[i-1][0])
    {
        // Remove the last node if it's empty
        temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
	i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);


    return head;
}




void checking_str(char **av, int ac)
{
	int i = 1;
	int j = 0;
	char **string;
	while(av[i])
	{
		j = 0;
		string = ft_split(av[i], ' ');
		while(string[j])
		{
			if (ft_isdigit2(string[j]) == 0)
			{
				printf("Error \n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		ft_free(string, j);
		i++;
	}
}

