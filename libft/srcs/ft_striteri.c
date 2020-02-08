/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:46:40 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/24 01:15:28 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de
** caractères passée en paramètre en précisant son index en premier
** argument. Chaque caractère est passé par adresse à la
** fonction f afin de pouvoir être modifié si nécéssaire.
*/

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t		i;
	size_t		y;

	if (!s || !f)
		return ;
	i = 0;
	y = ft_strlen(s);
	if (s != NULL)
		while (i < y)
			f(i++, s++);
}
