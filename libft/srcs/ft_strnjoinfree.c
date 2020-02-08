/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:45:50 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/22 05:32:25 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnjoinfree(char *s1, char *s2, size_t n, char del)
{
	char		*join;
	size_t		i;
	size_t		j;
	size_t		len;

	if ((!s1) || (!s2))
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	if (!(join = (char *)malloc(sizeof(char) * (len + n + 1))))
		return (0);
	while (i < len)
		join[i++] = s1[j++];
	j = 0;
	while (i < (len + n))
		join[i++] = s2[j++];
	join[i] = '\0';
	if (del == 'L' || del == 'B')
		free((char *)s1);
	if (del == 'R' || del == 'B')
		free((char *)s2);
	return (join);
}
