/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:37:17 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/07 12:33:21 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = ((unsigned char *)s);
	while (i < n)
	{
		if (str[i] == ((unsigned char)c))
			return (((unsigned char *)s) + i);
		i++;
	}
	return (NULL);
}
