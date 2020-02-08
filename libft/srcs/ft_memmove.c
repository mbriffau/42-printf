/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:01:03 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/02 22:54:53 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src < dst)
		while ((int)--len >= 0)
			*((char *)dst + len) = *((char *)src + len);
	else
		while (++i < len)
			*((char *)dst + i) = *((char *)src + i);
	return (dst);
}
