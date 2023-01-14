/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:31:51 by souledla          #+#    #+#             */
/*   Updated: 2023/01/12 18:41:49 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct l_list{
	int data;
	struct l_list *next;
} l_list;
int	ft_isdigit(int c);
int	ft_atoi(char *nptr);
void checking_double(int **str, int ac);
int **filling_array(int **str, int ac, char **av);
void checking_str(char **av, int ac);
void *create_node(int data);
void append_node(l_list **head, l_list *node);
int lst_size(l_list **head);
void swap_a(l_list **head);
void rra(l_list **stack_a);
void case3(l_list **head);
void ra(l_list **stack_a);
void push_a(l_list **stack_a, l_list **stack_b);
void case5(l_list **stack_a, l_list **stack_b) ;

#endif