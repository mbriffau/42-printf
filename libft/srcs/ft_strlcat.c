/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:55:08 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/07 13:57:49 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	src_size;
	size_t	dst_size;
	int		fin_size;
	char	*end_dest;

	if (!dst || !src)
		return (0);
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	fin_size = (int)size - (int)dst_size - 1;
	if (fin_size + 1 <= 0)
		return (src_size + size);
	end_dest = dst + dst_size;
	i = 0;
	while (i < fin_size && src[i])
	{
		end_dest[i] = src[i];
		i++;
	}
	end_dest[i] = '\0';
	return (src_size + dst_size);
}
