#include "push_swap.h"

void counting_index(l_list *stack_a, int x, int *index)
{
    int counter = 0;
    while (stack_a != NULL)
    {
        if (x > stack_a->data)
            counter++;
        stack_a = stack_a->next;
    }
    *index = counter;
}


void committing_index(l_list *stack_a)
{
    int i;
	int j; 
	l_list *temp;
	l_list *head;
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
