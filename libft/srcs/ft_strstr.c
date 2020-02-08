/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:55:08 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/06 15:23:42 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int littlel;
	int k;
	int sv;

	i = 0;
	littlel = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i])
	{
		k = 0;
		sv = i;
		while (big[sv] == little[k] && little[k] != 0)
		{
			k++;
			sv++;
		}
		if (k == littlel)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
