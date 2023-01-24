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

// void case100(l_list **stack_a, l_list **stack_b, int size) {
//     int chunk = size/6; 
//     int target = chunk; 
// 	int counter = 0;
//     l_list *current = *stack_a;
//     committing_index(*stack_b);
//     while ((*stack_b) != NULL) {
		
// 		if ((*stack_b) -> index < chunk)
// 		{
// 			push_a(stack_a, stack_b);	
// 			counter++;
// 		}	
// 		else if (counter == chunk)
// 		{

// 			chunk += target+7;
// 		}
// 		else 
// 		{
// 			ra(stack_b);

//     	}
// 	}
// }
// void case100(l_list **stack_a, l_list **stack_b, int size)
// {
// 	int counter = 0;
// 	committing_index(*stack_b);
// 	while (*stack_b != NULL)
// 	{
// 		if (counter == (size / 2))
// 			break;
// 		push_a(stack_a, stack_b);
// 		counter++;
// 	}
// }
void case1000(l_list **stack_a, l_list **stack_b, int size) {
    committing_index(*stack_b);
    int counter = 0;
    while (*stack_b != NULL && counter < 500) {
        l_list *current = *stack_b;
        *stack_b = (*stack_b)->next;
        current->next = *stack_a;
        *stack_a = current;
        counter++;
    }
    while (counter--)
        rra(stack_a);
}

void case100(l_list **stack_a, l_list **stack_b, int size)
{
	int chunk = 20;
	int counter = 0;
	//int size =lst_size(*stack_b);
	committing_index(*stack_b);
	while(*stack_b != NULL)
	{	
		if ((*stack_b) -> index >= (size - chunk))
		{
			push_a(stack_a, stack_b);
			counter++;
		}
		else if (counter == chunk)
		{
			chunk += 20;
		}
		else
			repush_to_b(stack_b, searching_for_index(stack_b, (*stack_b) -> index));
			//ra(stack_b);
	}
}
// 	//repush_to_b(stack_a, stack_b);
// }
// void poutin(l_list **stack_a, l_list **stack_b)
// {
// 	int position = 0;
// 	int max = check_biggest_index(*stack_a, &position);
// 	int index = searching_for_index(stack_a, max);
// 	int size = lst_size(*stack_a); 
// 	while((*stack_a) != NULL)
// 	{
// 		if ((*stack_a)-> data > (*stack_a))
// 			ra(stack_b);
// 		else if ()
// 	}
// }
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

// void sorting(l_list *stack_a,l_list *stack_b)
// {
// 	int max = searching_for_index(stack_a,lst_size(stack_a) - 1);
// 	int max_ = searching_for_index(stack_a,lst_size(stack_a) - 2);
// 	case100(&stack_a, &stack_b, lst_size(stack_b));
// 	l_list *ptr;
// 	ptr = stack_a;
// 	int flag_1 = -1;
// 	int flag_2 = -1;
// 	while (ptr != NULL)
// 	{
// 		if (flag_1 == -1 && flag_2 == -1)
// 		{
// 			max = searching_for_index(stack_a, lst_size(stack_a) - 1);
// 			max_ = searching_for_index(stack_a, lst_size(stack_a) - 1);
// 			flag_1  = 0;
// 			flag_2 = 0;
// 		}
// 		else if ((max  - lst_size(stack_a) / 2) > (max_  - lst_size(stack_a) / 2))
// 			ra(&stack_a);
// 		else if (max == 0)
// 		{
// 			push_a(&stack_b,&stack_a);
// 			flag_1 = -1;
// 		}
// 		else if (max_ == 0)
// 		{
// 			push_a(&stack_b,&stack_a);
// 			flag_2 = -1;
// 		}
// 	}

// }
// void sorting(l_list **stack_a)
// {
// 	int position;	
// 	int index;
// 	int new_index;
// 	int p = 0; 
// 	while ((*stack_a) != NULL) 
// 	{
// 		position = 0;
// 		index = check_biggest_index(*stack_a, &position);
// 		//printf("%d ", index);
//         while (index == check_biggest_index(*stack_a, &position)) 
// 		{
// 			if (position < (lst_size(*stack_a) / 2)) 
// 			{
//                 ra(stack_a);
//             } 
// 			else 
// 			{
//                 rra(stack_a);
//             }
//         }
//     }
// }
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
	return (min + i -1);
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
void repush_to_b(l_list **stack_b, int pos) { 
if(pos == -1)
	return;
if (pos < (lst_size(*stack_b) / 1.9)) 
	{
		ra(stack_b);
	} 
	else 
	{
		//printf("%d -------------",pos);
		rra(stack_b);
	}
}
    
// void repush_to_b(l_list **stack_a,l_list **stack_b)
// {
	
// 	int position = 0;
// 	int min= check_smallest_index(*stack_a);
// 	int len = lst_size(*stack_a);
// 	int index;
// 	while(*stack_a !=  NULL)
// 	{
// 		index = searching_for_index(stack_a, min);
// 		while (index == searching_for_index(stack_a, min))
// 		{
// 			if (index == 0)
// 			{
// 				push_a(stack_b, stack_a);
// 				min++;
// 				index = searching_for_index(stack_a, min);
// 				break;
// 			}
// 			// else if (index >= (lst_size(*stack_a) / 2)) 
// 			// 	ra(stack_a);
// 			else
// 				ra(stack_a);

//  		}
				
// 	}
// }
void sorting(l_list **stack_a, l_list **stack_b)
{
	
	int position = 0;
	int index_b;
	int max = check_biggest_index(*stack_a, &position);
	//int tmax =max;
	int size ;
	int index = searching_for_index(stack_a, max);
	//printf("%d ", index);
	while (((*stack_a) != NULL  && (checker(stack_a) != 0)))
	{
		// printf("index : %d\n", index);
		// printf("checkeer: %d\n", checker(stack_a));
		// printf("stack_b : %d\n", searching_for_index(stack_b, max));
		while (index == searching_for_index(stack_a, max))
		{
			if (index == lst_size(*stack_a) -1)
			{
				max--;
				index = searching_for_index(stack_a, max);
			}
			else if ((index == 1 && (searching_for_index(stack_a, (max - 1)) == 0)) || ((searching_for_index(stack_b, (max)) == 1) && (searching_for_index(stack_b, (max -1)) == 0)))
				{
					if ((index == 1 && (searching_for_index(stack_a, (max - 1)) == 0)))
					{
						swap_a(stack_a);
						index = searching_for_index(stack_a,max);
					}
					else if ((searching_for_index(stack_b, (max)) == 1) && (searching_for_index(stack_b, (max - 1)) == 0))
					{
						swap_a(stack_b);
					}
					else
					{
						ss(stack_a, stack_b);
						index = searching_for_index(stack_a,max);
					}
				}
			else if (searching_for_index(stack_a, max) == 0)
			{
				ra(stack_a);
				max--;
				index = searching_for_index(stack_a, max);
				break;
			}
			else if (searching_for_index(stack_a, max) == -1)
			{
				while ((*stack_b) != NULL)
				{
					if (searching_for_index(stack_b, max) == 0)
					{
						push_a(stack_a, stack_b);
						ra(stack_a);
						max--;
						index = searching_for_index(stack_a, (max));
						break;
					}
					//ra(stack_b);
					repush_to_b(stack_b, searching_for_index(stack_b, max));
				}
				break;
			}
			else
			{
				push_a(stack_b, stack_a);
				index = searching_for_index(stack_a, (max));
			}
			// printf("%d" ,searching_for_index(stack_a, (max)));
			// printf("%d" ,searching_for_index(stack_a, (max)));
		}
	}
	//printf("%d", max);
}


// void sorting(l_list **stack_a, l_list **stack_b)
// {

// 	int position = 0;
// 	int max = check_smallest_index(*stack_a);
// 	int index;
// 	int len;
// 	while( (*stack_a) != NULL)
// 	{
// 		index = searching_for_index(stack_a, max);
// 		//if (index == -1)
// 			//printf("error");
// 		while (index == searching_for_index(stack_a, max))
// 			{
// 				if (index == 0)
// 				{
// 					push_a(stack_b, stack_a);
// 					max++;
// 					len = lst_size(*stack_a) / 2;
// 					break;
// 				}
// 				else if (index <= len)
// 				{
// 					ra(stack_a);
// 				}
// 				else
// 				{
// 					rra(stack_a);
// 					//printf("%d", max);
// 				}

// 			}
// 	}		
// }
// void sorting(l_list **stack_a, l_list **stack_b)
// {
// 	int position = 0;
// 	int position1 = 0;
// 	int max = check_biggest_index(*stack_a, &position);
// 	int max1 = check_biggest_index(*stack_b, &position1);
// 	int index ;
// 	int index1 ;
// 	while ((stack_a != NULL  && max >= 0)|| (stack_b != NULL && max1 >= 0))
// 	{
// 		if (searching_for_index(stack_a, max) == -1 && searching_for_index(stack_b, max1) == -1)
// 			break;
// 		index = searching_for_index(stack_a, max);
// 		index1 = searching_for_index(stack_b, max1);
// 		while (index == searching_for_index(stack_a, max) || index1 == searching_for_index(stack_b, max1))
// 		{
// 			if ((index == 1 && (searching_for_index(stack_a, (max - 1)) == 0)) || ((searching_for_index(stack_b, (max)) == 1) && (searching_for_index(stack_b, (max -1)) == 0)))
// 			{
// 				if ((index == 1 && (searching_for_index(stack_a, (max - 1)) == 0)))
// 				{
// 					swap_a(stack_a);
// 				}
// 				else if ((searching_for_index(stack_b, (max)) == 1) && (searching_for_index(stack_b, (max - 1)) == 0))
// 				{
// 					swap_a(stack_b);
// 				}
// 				else
// 				{
// 					ss(stack_a, stack_b);
// 				}
// 			}
// 			else if (index == 0 || index1 == 0)
// 			{
// 				if (index == 0)
// 				{
// 					printf("-------------- im the prob -------------%d", max);
// 					push_a(stack_b, stack_a);
// 					index = searching_for_index(stack_a, max);
// 				}
// 				else if (index1 == 0)
// 				{
// 					push_a(stack_a, stack_b);
// 					max1--;
// 					index1 = searching_for_index(stack_b, max1);
// 				}
// 			}
// 			else
// 			{
// 				if (index > 0 && index1 > 0)
// 				{
// 					rr(stack_a, stack_b);
// 				}
// 				else if (index > 0)
// 				{
// 					repush_to_b(stack_a, index);
// 				}
// 				else if (index1 > 0)
// 				{
// 					repush_to_b(stack_b, index);
// 				}
// 			}
// 		}
// 	}
// }