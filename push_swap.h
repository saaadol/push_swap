/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:31:51 by souledla          #+#    #+#             */
/*   Updated: 2023/02/03 01:31:14 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct l_list{
	int data;
	int index;
	struct l_list *next;
} l_list;
int	ft_isdigit(int c);
int	ft_atoi(char *nptr);
void checking_double(l_list *stack_b);
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
l_list *filling_list(l_list *head, char *s);
void print_reverse(l_list *node) ;
int check_biggest_index(l_list *stack_a, int *position);
void a_rotation(l_list **stack_b, int pos);
void b_rotation(l_list **stack_b, int pos);
void push_b(l_list **stack_a, l_list **stack_b);
void rb(l_list **stack_a);
void sb(l_list **stack_a);
void rrb(l_list **head);
int searching_for_index(l_list **stack_a, int indexx);
int	ft_isdigit(int c);
void sorting(l_list **stack_a, l_list **stack_b);
void ss(l_list **stack_a, l_list **stack_b);
void util_stack_b(l_list **stack_a, l_list **stack_b, int *max, int *index);
void util(l_list **stack_a, l_list **stack_b, int *max , int *index);
void util_stack_a(l_list **stack_a, l_list **stack_b, int *max, int *index);
int check_smallest_index(l_list *stack_a);
void util_fill_stack_b(l_list **stack_a, l_list **stack_b, int *max , int *index);
int util3(l_list **stack_a, l_list **stack_b, int *max , int *index);
int util4(l_list **stack_a, l_list **stack_b, int *max , int *index);
void util5(l_list **stack_a, l_list **stack_b, int *max , int *index);
void else_statement(l_list **stack_a, l_list **stack_b, int *max , int *index);
void rr(l_list **stack_a, l_list **stack_b);
int lst_get_median(l_list *head, int size);
void test(l_list **stack_a,l_list **stack_b);
char	*ft_substr(char  *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int 	ft_atoi(char *nptr);
char	*ft_strjoin(char *s1, char  *s2);
void	ft_bzero(void *s, size_t n);
 char	**ft_free(char **str, size_t j);
int	ft_isdigit2(char  *str);

#endif