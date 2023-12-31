/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:37:54 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/02 10:53:13 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return (0);
	if (ft_argcheck(argv) == 0)
		return (write(2, "Error\n", 6));
	i = 1;
	while (argv[i])
		if (ft_atol(argv[i++]) == 3333333333)
			return (write(2, "Error\n", 6));
	if (ft_check_if_repeated_int(argv) == 1)
		return (write(2, "Error\n", 6));
	ft_full_push_swap(argv);
	return (0);
}
