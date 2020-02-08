/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:49:43 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/18 23:02:10 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(size_t option, char *s, char c, size_t with)
{
	size_t		i;
	size_t		len;
	char		*dst;

	i = 0;
	len = 0;
	if (with > 1 || option > 1 || !s || !c)
		return (0);
	len = ft_strlen_c(s, c);
	if (option)
	{
		if (!(dst = ft_strnew((ft_strlen(s) - len - 1) + with)))
			return (0);
		return (ft_strncpy(dst, &s[len + 1 - with],
			(ft_strlen(s) - len - 1) + with));
	}
	else
	{
		if (!(dst = ft_strnew(len + with)))
			return (0);
		return (ft_strncpy(dst, s, (len + with)));
	}
}
