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
	l_list *ptr;
	l_list *current;
	
	
	if (!(*stack_b))
		return ;
	else if (!*stack_a)
	{
		ptr = (*stack_b) -> next;
		*stack_a = *stack_b;
		*stack_b = ptr;
		(*stack_a) -> next = NULL;
	}
	else
	{
		ptr = *stack_b;
		current = (*stack_b) -> next;
		(*stack_b) -> next = *stack_a; 
		*stack_a = ptr;
		*stack_b = current; 
	}
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
	l_list *stack_a = NULL;
	l_list *stack_b = create_node(0);
	append_node(&stack_b,create_node(1));
	//append_node(&stack_b,create_node(2));
	rra(&stack_b);
	rra(&stack_b);
	//rb(&stack_b);
	
	while (stack_b != NULL)
	{
		printf("%d \n", stack_b -> data);
		stack_b = stack_b -> next;
	}

}