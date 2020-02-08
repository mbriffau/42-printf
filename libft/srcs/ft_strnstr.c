/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:59:36 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/06 15:27:53 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(char *big, const char *little, size_t len)
{
	size_t			i;
	int				str2l;
	int				k;
	size_t			sv;

	i = 0;
	str2l = ft_strlen(little);
	if (str2l == 0)
		return (big);
	while (big[i] && i < len)
	{
		k = 0;
		sv = i;
		while (big[sv] == little[k] && little[k] != 0 && sv < len)
		{
			k++;
			sv++;
		}
		if (k == str2l)
			return (big + i);
		i++;
	}
	return (NULL);
}
