/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:35:59 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/07 18:48:23 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *s)
{
	char		*srev;
	size_t		len;
	size_t		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(srev = (char *)malloc(len + 1)))
		return (NULL);
	srev[len] = '\0';
	while (len--)
	{
		srev[len] = s[i++];
	}
	return (srev);
}
