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
    l_list *current = stack_a;
    while (current != NULL)
    {
        counting_index(stack_a, current->data, &current->index);
        current = current->next;
    }
}
