/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:31:51 by souledla          #+#    #+#             */
/*   Updated: 2023/01/24 02:32:42 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct l_list{
	int data;
	int index;
	struct l_list *next;
} l_list;
int	ft_isdigit(int c);
int	ft_atoi(char *nptr);
void checking_double(int **str, int ac);
int **filling_array(int **str, int ac, char **av);
void checking_str(char **av, int ac);
void *create_node(int data);
void append_node(l_list **head, l_list *node);
int lst_size(l_list *head);
void swap_a(l_list **head);
void rra(l_list **stack_a);
void case3(l_list **head);
void ra(l_list **stack_a);
void push_a(l_list **stack_a, l_list **stack_b);
void case5(l_list **stack_a, l_list **stack_b);
void counting_index(l_list *stack_a, int x, int *index);
void committing_index(l_list *stack_a);
void case100(l_list **stack_a, l_list **stack_b, int size);
void sorted_insert(l_list **head, l_list *new_node);
void insertion_sort(l_list **head);
l_list* get_last_node(l_list* head);
void print_reverse(l_list *node) ;
int check_biggest_index(l_list *stack_a, int *position);
void repush_to_b(l_list **stack_a, int pos);
int searching_for_index(l_list **stack_a, int indexx);
void sorting(l_list **stack_a, l_list **stack_b);
void ss(l_list **stack_a, l_list **stack_b);
// void sorting(l_list *stack_a, l_list *stack_b);
void case1000(l_list **stack_a, l_list **stack_b, int size);
int check_smallest_index(l_list *stack_a);
void rr(l_list **stack_a, l_list **stack_b);

#endif