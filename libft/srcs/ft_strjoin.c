/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:44:17 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/02 23:11:58 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	size_t		i;
	size_t		i2;

	i = 0;
	i2 = 0;
	if ((!s1) || (!s2))
		return (0);
	if (!(join = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (0);
	while (i < ft_strlen(s1))
		join[i++] = s1[i2++];
	i2 = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
		join[i++] = s2[i2++];
	join[i] = '\0';
	return (join);
}
