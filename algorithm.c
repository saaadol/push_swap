#include "push_swap.h"
void case3(l_list **head)
{
    l_list *current = *head;

    if (((*head) -> data > (*head) -> next -> data) && ((*head) -> next -> data < (*head) -> next -> next -> data) && ((*head) -> data < (*head) -> next -> next -> data))
        swap_a(head);
    else if (((*head) -> data > (*head) -> next -> data) && ((*head) -> next -> data > (*head) -> next -> next -> data))
    {
        swap_a(head);
        rra(head);
    }
    else if (((*head) -> data > (*head) -> next -> data) && ((*head) -> next -> data < (*head) -> next -> next -> data) && ((*head) -> data > (*head) -> next -> next -> data))
        ra(head);
    else if (((*head) -> data < (*head) -> next -> data) && ((*head) -> next -> data > (*head) -> next -> next -> data) &&  ((*head) -> data < (*head) -> next -> next -> data))
    {
        swap_a(head);
        ra(head);
    }
    else if (((*head) -> data < (*head) -> next -> data) && ((*head) -> next -> data > (*head) -> next -> next -> data) &&  ((*head) -> data > (*head) -> next -> next -> data))
        rra(head);
}
void case5(l_list **stack_a, l_list **stack_b) 
{
    push_a(stack_b, stack_a);
    push_a(stack_b, stack_a);
    if (((*stack_b) -> data) < ((*stack_b) -> next -> data))
        swap_a(stack_b);
    case3(stack_a);
    push_a(stack_a, stack_b);
    ra(stack_a);
    push_a(stack_a, stack_b); 
}
// int how_many_moves()
// case 100
void case100(l_list **stack_a, l_list **stack_b)
{
	int len;
	int chunk = 20;
	int counter = 0;
	int rem;
	l_list *current1 = *stack_a;
	l_list *current2 = *stack_b;
	len = lst_size(stack_b);
	//printf("%d", len);
	printf("%d \n \n", (*stack_b) -> next -> index);
	while (*stack_b != NULL)
	{
		if ((*stack_b) -> index < (chunk / 2))
		{
			
			push_a(stack_a, stack_b);
			counter++;
		}
		else if  ((*stack_b) -> index >= chunk / 2)
		{
			push_a(stack_a, stack_b);
			ra(stack_a);
			counter++;
		}
		*stack_b = (*stack_b) -> next;
	}
	*stack_a = current1;
	*stack_b = current2;
}