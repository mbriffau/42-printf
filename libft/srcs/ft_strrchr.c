/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:55:08 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/05 22:50:46 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		cmp;
	size_t		len;
	char		*str;

	i = 0;
	str = NULL;
	len = ft_strlen(s);
	cmp = (char)c;
	while (i <= len)
	{
		if (s[i] == cmp)
			str = (((char *)s + i));
		i++;
	}
	if (str == NULL)
		return (NULL);
	return (str);
}
