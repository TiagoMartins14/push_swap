/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:39:45 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/17 11:11:29 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct s_stack
{
	int	num;
	int cost;
	int pos;
	int rev_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_create_stack(char **argv);

long	ft_atol(char *str);

void	ft_push_swap(t_stack *stack_a);
void	ft_swap_top_two(t_stack **head);
void	ft_push_to_stack(t_stack **head_x, t_stack **head_y);
void	ft_bottom_to_top(t_stack **head);
void	ft_top_to_bottom(t_stack **head);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack);
void	ft_update_pos(t_stack *stack);
void	ft_update_cost(t_stack *stack_a, t_stack *stack_b);
void	ft_operation_aid(t_stack **stack_a, t_stack **stack_b);
void	ft_operation(t_stack **stack_a, t_stack **stack_b);

int	ft_is_stack_sorted(t_stack *stack);
int	ft_check_min(t_stack *stack);
int	ft_check_max(t_stack *stack);
int ft_cost(t_stack *head_a, t_stack *head_b, int position);
int ft_lowest_cost(int position_a, int position_b, int len_a, int len_b);
int	ft_stack_len(t_stack *stack);
int	ft_big_or_small(int num, t_stack *stack);
int	ft_highest_low(t_stack *stack, int num);
int	ft_cheapest_option(t_stack *stack_a);

#endif