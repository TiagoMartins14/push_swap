/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:32:31 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 11:38:09 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (1); //NOT sorted
		stack = stack->next;
	}
	return (0); // Sorted
}

int	ft_check_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (min > stack->num)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	ft_check_max(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int ft_lowest_cost(int position_a, int position_b, int len_a, int len_b)
{
	int	cost;

	cost = position_a - 1; // Cost of only A going up
	if (cost < position_b - 1)
		cost = position_b - 1; // A and B up
	if (cost > ((position_a - 1) + (len_b - position_b + 1))) // A up and B down
		cost = ((position_a - 1) + (len_b - position_b + 1));
	if (cost > len_a - position_a + 1 && cost > len_b - position_b + 1) // A and B down
		{
			if ((len_a - position_a + 1) > (len_b - position_b + 1))
				cost = len_a - position_a + 1;
			else
				cost = len_b - position_b + 1;
		}
	if (cost > (len_a - position_a + 1) + position_b - 1) // A down and B up
		cost = (len_a - position_a + 1) + position_b - 1;
	return (cost);
}

int ft_cost(t_stack *head_a, t_stack *head_b, int position)
{
	int	cost;
	int	highest_low; // Highest lower number in head_b compared to head_a->num
	int len_a;
	int	len_b;

	len_a = ft_stack_len(head_a);
	len_b = ft_stack_len(head_b);
	while (head_a->position != position) // Move to the node 'A' that matches 'position'
		head_a = head_a->next;
	highest_low = ft_highest_low(head_b, head_a->num);
	while (head_b->num != highest_low) // Move to the node with the highest low
		head_b = head_b->next;	
	cost = ft_lowest_cost(head_a->position, head_b->position, len_a, len_b);
	return (cost);
}
