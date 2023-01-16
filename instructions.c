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
	if (!(*stack_a) || !((*stack_a)->next))
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
    l_list *stack_a = NULL;
    l_list *stack_b = NULL;
    int i = 0;
    while (i < 100)
    {
        l_list *new_node = malloc(sizeof(l_list));
        new_node->data = rand() % 100;
        new_node->next = stack_b;
        stack_b = new_node;
        i++;
    }
    committing_index(stack_b);
    int size = lst_size(&stack_b);
    case100(&stack_a, &stack_b, size);
    printf("Sorted Stack: ");
    l_list *current = stack_a;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}



