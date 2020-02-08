/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:44:17 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/06 17:44:55 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		a;
	int		neg;
	char	*str;

	i = 1;
	neg = (n < 0) ? 1 : 0;
	if (n > 0)
		n = n * -1;
	a = n;
	while ((a = a / 10) < 0)
		i++;
	str = (char *)malloc((sizeof(char) * i) + neg + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, i + neg + 1);
	if (neg == 1)
		str[0] = '-';
	i -= 1 - neg;
	while (i-- >= neg)
	{
		str[i + 1] = (-(n % 10) + '0');
		n = n / 10;
	}
	return (str);
}
