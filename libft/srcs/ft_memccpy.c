/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:55:08 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/07 12:10:28 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
			return (&dst[i + 1]);
		}
		((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (NULL);
}
