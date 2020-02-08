/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:55:08 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/05 22:24:00 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	size_t		lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	while (src[i] && (i < len))
	{
		dst[i] = src[i];
		i++;
	}
	if (lensrc < len)
		ft_bzero(&dst[i], len - i);
	return (dst);
}
