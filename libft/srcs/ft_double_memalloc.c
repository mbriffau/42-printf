/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_memalloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:30:45 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/22 04:25:01 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	if (!(str = ft_strnew(n)))
		return (NULL);
	str = ft_strncpy(str, (char *)s, n);
	str[n] = '\0';
	return (str);
}
