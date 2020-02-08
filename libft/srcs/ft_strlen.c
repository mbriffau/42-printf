/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:05:39 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/24 10:00:39 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** size_t		ft_strlen(char const *str)
** {
**
** 	size_t		i;
** 	size_t		n;
**
** 	i = 0;
** 	n = 32768;
** 	while (str[i])
** 	{
** 		if (str[i + n] != 0)
** 			i += n;
** 		else
** 		{
** 			n >>= 1;
** 			i++;
** 		}
** 	}
** 	return (i); a revoir
** }
*/

size_t			ft_strlen(char const *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
