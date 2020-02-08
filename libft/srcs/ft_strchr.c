/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:10:01 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/05 22:37:30 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		cmp;
	size_t		len;
	char		*str;

	i = 0;
	str = ((char*)s);
	len = ft_strlen(s);
	cmp = (char)c;
	while (i <= len)
	{
		if (str[i] == cmp)
			return (((char *)str + i));
		i++;
	}
	return (NULL);
}
