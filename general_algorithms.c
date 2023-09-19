/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:56 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 07:58:54 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_top_two(t_stack **head)
{
	int	temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = temp;
}

void	ft_bottom_to_top(t_stack **head)
{
    if (*head == NULL || (*head)->prev == *head)
        return;
    *head = (*head)->prev;
}

void	ft_top_to_bottom(t_stack **head)
{
    if (*head == NULL || (*head)->next == *head)
        return;
    *head = (*head)->next;
}

void	ft_push_to_stack(t_stack **stack_x, t_stack **stack_y)
{
    t_stack *temp;

    temp = *stack_x;
	if (ft_stack_len(*stack_x) == 1)
        *stack_x = NULL;
	else
	{
		(*stack_x)->prev->next = (*stack_x)->next;
		(*stack_x)->next->prev = (*stack_x)->prev;
		*stack_x = (*stack_x)->next;
	}
    if (!(*stack_y))
    {
        *stack_y = temp;
        (*stack_y)->next = *stack_y;
        (*stack_y)->prev = *stack_y;
    }
    else
    {
		(*stack_y)->prev->next = temp;
		temp->prev = (*stack_y)->prev;
		(*stack_y)->prev = temp;
		temp->next = *stack_y;
		(*stack_y) = (*stack_y)->prev;
    }
}