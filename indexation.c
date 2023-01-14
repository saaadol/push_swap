#include "push_swap.h"

void counting_index(l_list **stack_a, int x, int *index)
{
	l_list *current = *stack_a;
	int counter = 0;
	while (*stack_a != NULL)
	{
		if (((*stack_a) -> next != NULL) &&  (x > (*stack_a) -> next -> data))
			counter++;
		*stack_a = (*stack_a) -> next;
	}
	*index = counter;
	*stack_a = current;	
}
void committing_index(l_list **stack_a)
{
	l_list *current = *stack_a;
	while (*stack_a != NULL)
	{
		counting_index(&current, (*stack_a) -> data, &(*stack_a) -> index);
		*stack_a = (*stack_a) -> next;
	}
	*stack_a = current;
}