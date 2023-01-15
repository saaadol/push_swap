#include "push_swap.h"
void swap_a(l_list **head)
{
	if (!*head || !(*head) -> next)
		return ;
	int temp1;
	int temp2;
	l_list *current = *head;
	temp1 = (*head) ->	data;
	temp2 = (*head) -> next -> data;
	*head = current;
	(*head) -> data = temp2;
	(*head) -> next -> data = temp1;
}

void push_a(l_list **stack_a, l_list **stack_b)
{
    if (!(*stack_b))
        return ;
    l_list *new_node = malloc(sizeof(l_list));
    new_node->data = (*stack_b)->data;
    new_node->next = *stack_a;
    *stack_a = new_node;
    l_list *temp = *stack_b;
    *stack_b = (*stack_b)->next;
    free(temp);
}

void ra(l_list **stack_a)
{
	if (!(*stack_a))
		return ;
	int current_data_node;
	l_list *current;
	current = *stack_a;
	current_data_node = (*stack_a) -> data; 
	while ((*stack_a) -> next != NULL)
	{
		(*stack_a) -> data = (*stack_a) -> next -> data;
		(*stack_a) -> next -> data  = current_data_node;  
		(*stack_a) = (*stack_a) -> next; 
	}
	*stack_a = current;
}

void rra(l_list **stack_a)
{ 
	if (! (*stack_a) -> next)
		return ;
	l_list *current;
	l_list *last; 
	current = *stack_a;
	
	while ((*stack_a) != NULL)
	{
		if ((*stack_a) -> next -> next == NULL)
		{
			last = (*stack_a) -> next ;
			last -> next = current;
			(*stack_a) -> next = NULL;
			break;
		}
		
		*stack_a = (*stack_a) -> next;
	}
	*stack_a = last; 
}


int main()
{
	int i = 0;
	int x;
	l_list *stack_a = create_node(0);
	l_list *stack_b = create_node(0);
	while (i < 100)
	{
		append_node(&stack_b, create_node(rand() % 100));
		i++;
	}
	
	
	// l_list *stack_b = create_node(0);
	committing_index(stack_b);
	case100(&stack_a, &stack_b);
	
	while (stack_a != NULL)
	{
		printf(" data -> %d , index -> %d \n", stack_a -> data, stack_a -> index);
		stack_a = stack_a -> next;
	}
}
