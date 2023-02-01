#include "push_swap.h"
#include <time.h>
void swap_a(l_list **stack_a) {
    l_list *first = *stack_a;
    l_list *second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
	printf("stack \n");
}

void push_a(l_list **stack_a, l_list **stack_b)
{
    if (!(*stack_b))
        return ;
    l_list *head = 	*stack_b;
	*stack_b = (*stack_b) -> next;
	head -> next = (*stack_a);
	*stack_a = head;
	printf("push_a \n");
}

void ra(l_list **stack_a)
{
	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	l_list *head;
	l_list	*current;
	
	current = *stack_a;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	while (head->next != NULL)
	{
		head = head -> next; 
	}
	head -> next = current;
	head->next->next = NULL;

	printf("ra \n");
}
void ss(l_list **stack_a, l_list **stack_b)
{
	swap_a(stack_a);
	swap_a(stack_b);
	printf("ss \n");
}

void rr(l_list **stack_a, l_list **stack_b)
{
	ra(stack_a);
	ra(stack_b);
	printf("rr \n");
}

void rra(l_list **head) {
 if (*head == NULL || (*head)->next == NULL) {
        return;
 }
    l_list *last = *head;
    l_list *prev = NULL;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *head;
    *head = last;
	printf("rra \n");
}
/*
int main()
{
	int i, j, temp, nums[100];
    l_list *stack_b = NULL;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the array with integers from 1 to 100
    for (i = 0; i < 100; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the array using the Fisher-Yates algorithm
    for (i = 99; i > 0; i--) {
        j = rand() % (i + 1);
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Add the first 100 integers to the linked list
    for (i = 0; i < 100; i++) {
        l_list *node = create_node(nums[i]);
        node->next = stack_b;
        stack_b = node;
    }
    
	l_list *current = stack_b;
	int size = lst_size(stack_b);

	// while (current != NULL)
    // {
    //     printf("num -> %d , index -> %d \n", current->data, current->index);
    //     current = current->next;
    // }
	l_list *stack_a = NULL;
 	case100(&stack_a, &stack_b, size);
	//printf("%d", searching_for_index(&stack_a,  check_smallest_index(stack_a)));
	
	// int  pos = 0;
	sorting(&stack_a, &stack_b);
	// printf("%d", pos);
	//printf(" %d",pos);
	//committing_index(stack_b);
	// int position = 0;
	//repush_to_b(&stack_a, &stack_b);
	//case3(&stack_b);
	//sorting(&stack_a, &stack_b);
    current = stack_a;
	int position = 0;
    while (current != NULL)
    {
		printf("%d \n", current->data);
		current = current->next;
	}
	//printf("%d", searching_for_index(stack_a, 91));
	//printf("%d",stack_a -> next -> index);
	//printf("%d", current -> next ->  index);
	//l_list *empty = NULL;
	// l_list *test = create_node(0);
	// append_node(&test, create_node(1));
	// append_node(&test, create_node(2));
	// append_node(&test, create_node(3));
	// swap_a(&test);
	
	// while (test)
	// {
	// 	printf("%d \n", test -> data);
	// 	test = test -> next;
	// }

}
*/



