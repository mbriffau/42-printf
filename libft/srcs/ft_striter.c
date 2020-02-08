/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:46:40 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/24 01:16:11 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de
** caractères passée en paramètre. Chaque caractère est passé
** par adresse à la fonction f afin de pouvoir être modifié si
** nécéssaire.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	if (s != NULL)
		while (*s)
		{
			f(s++);
		}
}
