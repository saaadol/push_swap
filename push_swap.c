/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:21:01 by souledla          #+#    #+#             */
/*   Updated: 2023/01/10 16:39:53 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int main(int argc, char **argv)
{
    if((argc == 1))
    {
        printf("Error \n");
        exit(EXIT_FAILURE);
    }
	l_list *stack_b;
    checking_str(argv, argc);
    stack_b = filling_list(stack_b,argc, argv);
    l_list *stack_a;
	committing_index(stack_b);
	case100(&stack_a,&stack_b,lst_size(stack_b));
	sorting(&stack_a, &stack_b);
	l_list *current = stack_a;
    while (current != NULL)
    {
        printf("Data: %d  index : %d\n", current->data, current->index);
        current = current->next;
    }
   // printf("%d", INT_MAX);
    current = stack_b;
    while (current != NULL)
    {
        l_list *tmp = current->next;
        free(current);
        current = tmp;
    }
    return 0;
}



char *ft_join(char **strs, int size, char c)
{
    int i, j, k, len, tot_len;
    char *joined;

    tot_len = 0;
    for (i = 0; i < size; i++)
        tot_len += strlen(strs[i]) + 1;
    joined = (char *)malloc(tot_len + (size - 1) + 1);
    if (!joined)
        return (NULL);
    k = 0;
    for (i = 0; i < size; i++)
    {
        len = strlen(strs[i]);
        for (j = 0; j < len; j++)
            joined[k++] = strs[i][j];
        if (i != size - 1)
            joined[k++] = c;
    }
    joined[k] = '\0';
    return (joined);
}

int main(int argc, char **argv)
{
    if((argc == 1))
    {
        printf("Error \n");
        exit(EXIT_FAILURE);
    }
   // checking_str(argv, argc);
	l_list *stack_b = NULL; 
    
    char *joined = ft_join(argv + 1, argc - 1, ' ');
    stack_b = filling_list(stack_b,joined);
    l_list *stack_a;
	//committing_index(stack_b);
	//case100(&stack_a,&stack_b,lst_size(stack_b));
	//sorting(&stack_a, &stack_b);
	l_list *current = stack_b;
    while (current != NULL)
    {
        printf("Data: %d  index : %d\n", current->data, current->index);
        current = current->next;
    }
    current = stack_b;
    while (current != NULL)
    {
        l_list *tmp = current->next;
        free(current);
        current = tmp;
    }
    return 0;
}
*/
char *ft_join(char **strs, int size, char c)
{
    int i, j, k, len, tot_len;
    char *joined;

    tot_len = 0;
    for (i = 0; i < size; i++)
        tot_len += strlen(strs[i]) + 1;
    joined = (char *)malloc(tot_len + (size - 1) + 1);
    if (!joined)
        return (NULL);
    k = 0;
    for (i = 0; i < size; i++)
    {
        len = strlen(strs[i]);
        for (j = 0; j < len; j++)
            joined[k++] = strs[i][j];
        if (i != size - 1)
            joined[k++] = c;
    }
    joined[k] = '\0';
    return (joined);
}
int main(int argc, char **argv)
{
    if((argc == 1))
    {
        printf("Error \n");
        exit(EXIT_FAILURE);
    }
   // checking_str(argv, argc);
	l_list *stack_b;
    
    char *joined = ft_join(argv + 1, argc - 1, ' ');
    int len = strlen(joined);
    joined[len] = ' ';
    joined[len + 1] = '\0';
    stack_b = filling_list(stack_b,joined);
    l_list *stack_a = NULL;
	committing_index(stack_b);
	//case100(&stack_a,&stack_b,lst_size(stack_b));
	//sorting(&stack_a, &stack_b);
	l_list *current = stack_b;
    printf("%s", stack_b -> next -> next );
    while (current != NULL)
    {
        printf("Data: %d  index : %d\n", current->data, current->index);
        current = current->next;
    }
    current = stack_b;
    while (current != NULL)
    {
        l_list *tmp = current->next;
        free(current);
        current = tmp;
    }
    return 0;
}





