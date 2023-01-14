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