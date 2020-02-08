/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:44:17 by mbriffau          #+#    #+#             */
/*   Updated: 2016/11/22 16:44:11 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*mem;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(mem = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = len + start;
	while ((s[start] != 0) && (start < len))
	{
		mem[i] = s[start];
		i++;
		start++;
	}
	mem[i] = '\0';
	return (mem);
}
