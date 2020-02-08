/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:56:16 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/07 12:38:27 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		x;
	int		y;

	y = 0;
	x = ft_strlen(src);
	if (!(dest = malloc(sizeof(char) * (x + 1))))
		return (NULL);
	while (y < x)
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
