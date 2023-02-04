#include "push_swap.h"
void case3(l_list **head)
{
    l_list *current = *head;

    if (((*head) -> data > (*head) -> next -> data) && ((*head) -> next -> data < (*head) -> next -> next -> data) && ((*head) -> data < (*head) -> next -> next -> data))
        swap_a(head);
    else if (((*head) -> data > (*head) -> next -> data) && ((*head) -> next -> data > (*head) -> next -> next -> data) && ((*head) -> data > (*head) -> next -> next -> data))
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
	else
		*head = current; 
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

void case100(l_list **stack_a, l_list **stack_b, int size)
{
	int chunk = 30;
	int counter = 0;
	while(*stack_a != NULL)
	{	
	if ((*stack_a) -> index < chunk)
		{
			push_b(stack_b, stack_a);
			counter++;
		}
		else if (counter == chunk)
		{
			if (size > 100)
				chunk += 30;
			else
				chunk += 15;
		}
		else
		{
			a_rotation(stack_a, searching_for_index(stack_a, (*stack_a) -> index));
		}
	}
}

void a_rotation(l_list **stack_b, int pos) { 

  if(pos == -1)
    return;
    if (pos < (lst_size(*stack_b) / 2)) {
      ra(stack_b);
    } 
	else {
      rra(stack_b);
    }
  
}
void b_rotation(l_list **stack_b, int pos) { 

  if(pos == -1)
    return;
    if (pos < (lst_size(*stack_b) / 2)) {
      rb(stack_b);
    } 
	else {
      rrb(stack_b);
    }
}
int searching_for_index(l_list **stack_a, int indexx)
{
	l_list *ptr;
	int counter = 0;
	int position = 0; 
	int flag = -1;
	ptr = *stack_a;
	while((*stack_a) != NULL)
	{
		if ((*stack_a) -> index == indexx)
		{
			position = counter;
			flag = 0;
		}
		counter++;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = ptr;
	if (flag == -1)
	{
		return flag;

	}
	return position;
}

int check_biggest_index(l_list *stack_a, int *position)
{
	static int i=0;
	l_list *ptr;
	int max;
	int stach = 0; 
	ptr = stack_a;
	max = ptr -> index;
	while (ptr != NULL)
	{
		if (ptr -> index > max)
		{
			stach = *position; 
			max = ptr -> index;
		}
		(*position)++;
		ptr = ptr -> next;		
	}
	*position = stach;
	free(ptr);
	i++;

	return (max - i +1);
}
int check_smallest_index(l_list *stack_a)
{
	static int i= -1;
	l_list *ptr;
	int min; 
	ptr = stack_a;
	min = ptr -> data;
	while (ptr != NULL)
	{
		if (ptr -> data < min)
		{ 
			min = ptr ->data;
		}
		ptr = ptr -> next;		
	}
	free(ptr);
	i++;
	if ((min + i - 1) < 0)
		return 0;
	return (min +i -1);
}
int checker(l_list **stack_a)
{
	int position = 0;
	l_list *current =  *stack_a;
	int counter = 0;
	int max = check_biggest_index(*stack_a, &position)+1;
	//printf("%d", (*stack_a)-> next -> data);
	while (counter <= max)
	{
		if ((*stack_a) -> index != counter)
		{
			*stack_a = current;
			return -1;
		}
		*stack_a = (*stack_a) -> next;  
		counter++;

	}
	*stack_a = current;
	return 0;
}

int check_biggest_index2(l_list *stack_a)
{
	l_list *ptr;
	int max; 
	ptr = stack_a;
	max = ptr -> index;
	while (ptr != NULL)
	{
		if (ptr -> index > max)
			max = ptr -> index;
		ptr = ptr -> next;		
	}
	
	return (max);
}
// void sorting(l_list **stack_a, l_list **stack_b)
// {

// 	int position = 0;
// 	int index_b;
// 	int counter = 0;
// 	int max = check_biggest_index(*stack_a,&position);
// 	//int tmax =max;
// 	int size  = lst_size(*stack_a) / 4;
// 	int index = searching_for_index(stack_a, max);
// 	while (((*stack_a) != NULL  && (checker(stack_a) != 0)))
// 	{
// 		while (index == searching_for_index(stack_a, max))
// 		{
// 			if (index == lst_size(*stack_a) -1)
// 			{
// 				max--;
// 				index = searching_for_index(stack_a, max);
// 			}
// 			else if ((index == 1 && (searching_for_index(stack_a, (max - 1)) == 0)) 
// 				|| ((searching_for_index(stack_b, (max)) == 1) && (searching_for_index(stack_b, (max -1)) == 0)))
// 				{
// 					if ((index == 1 && (searching_for_index(stack_a, (max - 1)) == 0)))
// 					{
// 						swap_a(stack_a);
// 						index = searching_for_index(stack_a,max);
// 					}
// 					else if ((searching_for_index(stack_b, (max)) == 1) && (searching_for_index(stack_b, (max -1)) == 0))
// 					{
// 						swap_b(stack_b);
// 					}
// 					else
// 					{
// 						ss(stack_a, stack_b);
// 						index = searching_for_index(stack_a,max);
// 					}
// 				}
// 			else if (searching_for_index(stack_a, max) == 0)
// 			{
// 				ra(stack_a);
// 				max--;
// 				index = searching_for_index(stack_a, max);
// 				break;
// 			}
// 			else if (searching_for_index(stack_a, max) == -1)
// 			{
// 				while ((*stack_b) != NULL)
// 				{
// 					if (searching_for_index(stack_b, max) == 0)
// 					{
// 						push_a(stack_a, stack_b);
// 						ra(stack_a);
// 						max--;
// 						index = searching_for_index(stack_a, (max));
// 						break;
// 					}	
// 					b_rotation(stack_b, searching_for_index(stack_b, max));
// 				}
// 				break;
// 			}
// 			else
// 			{
// 				push_b(stack_b, stack_a);
// 				index = searching_for_index(stack_a, (max));
// 			}	
// 		}
// 	}
// }
void test(l_list **stack_a,l_list **stack_b)
{
	while(*stack_b != NULL)
	{
		//rrb(stack_b);
		push_a(stack_a, stack_b);
	}
}
void sorting(l_list **stack_a,l_list **stack_b)
{
	int position = 0 ;
	int max = check_biggest_index(*stack_b, &position);
	int flag = 0;
	int index = searching_for_index(stack_b, max);
		while ((*stack_b) != NULL && index == searching_for_index(stack_b, max))
		{
			if ((*stack_a) && (*stack_a) -> next && (*stack_a) -> data > (*stack_a) -> next -> data)
			{
				swap_a(stack_a);
				max--;
				index = searching_for_index(stack_b, max);
				//printf("%d------------------", index);
			}
			else if ((searching_for_index(stack_b, (max - 1)) == 0))
			{
				push_a(stack_a,stack_b);
				index = searching_for_index(stack_b, max);
			}
			else if (index == 2 && (searching_for_index(stack_b, (max - 1)) == 0))
			{
				push_a(stack_a,stack_b);
				max--;
				ra(stack_b);
				push_a(stack_a,stack_b);
				max--;
				swap_a(stack_a);
				index = searching_for_index(stack_b, max);
			}
			else if (index == 1 && (searching_for_index(stack_b, (max - 1)) == 0)) 
				{
						swap_b(stack_b);
						index = searching_for_index(stack_b,max);
				
				}
			else if (searching_for_index(stack_b, max) == 0)
			{
				push_a(stack_a,stack_b);
				max--;
				index = searching_for_index(stack_b, max);
			}
			else 
			{
				b_rotation(stack_b,index);
				index = searching_for_index(stack_b, max);
			}
	}
	if ((*stack_b) == NULL && (*stack_a) -> data > (*stack_a) -> next -> data)
		swap_a(stack_a);
}