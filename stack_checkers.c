/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:32:31 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/02 10:54:30 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Return 1: not sorted
//Return 0: sorted
int	ft_is_stack_sorted(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (1);
		stack = stack->next;
		if (stack->next == head)
			break ;
	}
	return (0);
}

int	ft_check_min(t_stack *stack)
{
	int		min;
	t_stack	*head;

	min = stack->num;
	head = stack;
	while (stack)
	{
		if (min > stack->num)
			min = stack->num;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (min);
}

int	ft_check_max(t_stack *stack)
{
	int		max;
	t_stack	*head;

	max = stack->num;
	head = stack;
	while (stack)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (max);
}

int	ft_lowest_cost(int position_a, int position_b, int len_a, int len_b)
{
	int	cost;

	cost = position_a - 1;
	if (cost < position_b - 1)
		cost = position_b - 1;
	if (cost > ((position_a - 1) + (len_b - position_b + 1)))
		cost = ((position_a - 1) + (len_b - position_b + 1));
	if (cost > len_a - position_a + 1 && cost > \
	len_b - position_b + 1)
	{
		if ((len_a - position_a + 1) > (len_b - position_b + 1))
			cost = len_a - position_a + 1;
		else
			cost = len_b - position_b + 1;
	}
	if (cost > (len_a - position_a + 1) + position_b - 1)
		cost = (len_a - position_a + 1) + position_b - 1;
	return (cost);
}

int	ft_cost(t_stack *head_a, t_stack *head_b, int position)
{
	int	len_a;
	int	len_b;
	int	cost;
	int	highest_low;

	len_a = ft_stack_len(head_a);
	len_b = ft_stack_len(head_b);
	while (head_a->pos != position)
		head_a = head_a->next;
	highest_low = ft_highest_low(head_b, head_a->num);
	while (head_b->num != highest_low)
		head_b = head_b->next;
	cost = ft_lowest_cost(head_a->pos, head_b->pos, len_a, len_b);
	return (cost);
}
