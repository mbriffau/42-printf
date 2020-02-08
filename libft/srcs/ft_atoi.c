/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:46:49 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/06 20:21:46 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int i;
	int j;
	int neg;

	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	j = i;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' && j == i)
	{
		neg = -1;
		i++;
	}
	j = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		j = j * 10 + (str[i] - 48);
		i++;
	}
	j *= neg;
	return (j);
}
