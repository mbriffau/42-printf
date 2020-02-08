/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 01:07:58 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/22 01:26:05 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char		*dest;
	size_t		y;

	y = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (y < n)
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
