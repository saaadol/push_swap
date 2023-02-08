/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:31:51 by souledla          #+#    #+#             */
/*   Updated: 2023/02/07 17:50:23 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct t_list{
	int				data;
	int				index;
	struct t_list	*next;
}	t_list;
int		ft_isdigit(int c);
int		ft_atoi(char *nptr);
void	checking_double(t_list *stack_b);
void	checking_str(char **av);
int		lst_size(t_list *head);
void	swap_a(t_list **head);
void	rra(t_list **stack_a);
void	case3(t_list **head);
void	ra(t_list **stack_a);
void	push_a(t_list **stack_a, t_list **stack_b);
void	case5(t_list **stack_a, t_list **stack_b);
void	counting_index(t_list *stack_a, int x, int *index);
void	committing_index(t_list *stack_a);
void	case100(t_list **stack_a, t_list **stack_b, int size);
t_list	*filling_list(t_list *head, char *s);
int		check_biggest_index(t_list *stack_a);
void	a_rot(t_list **stack_b, int pos);
void	b_rotation(t_list **stack_b, int pos);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack_a);
void	swap_b(t_list **stack_a);
void	rrb(t_list **head);
int		searching_for_index(t_list **stack_a, int indexx);
int		ft_isdigit(int c);
void	sorting(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *nptr);
char	**ft_free(char **str, size_t j);
int		ft_isdigit2(char *str);
int		ft_strlen(char *str);
int		util(t_list **stack_a, t_list **stack_b, int *max, int index);
int		util1(t_list **stack_a, t_list **stack_b, int *max, int index);
void	filling_util(t_list **head, t_list **temp, char **split);
int		sorting_check(t_list *stack_a);
void	print_error(void);
void	case3(t_list **stack_a);
void	case3_utl(t_list **stack_a);
void	case5(t_list **stack_a, t_list **stack_b);
int		check_smallest_index(t_list *stack_a);
#endif