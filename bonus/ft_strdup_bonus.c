/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:13:22 by tiago             #+#    #+#             */
/*   Updated: 2023/10/02 10:53:27 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i <= len)
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	return (new_str);
}
