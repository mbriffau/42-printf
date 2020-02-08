/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:32:12 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/18 23:21:14 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_conv	*option_no_conv(t_printf *pf, int len, char c, t_conv *conv)
{
	int			i;
	char		tab[(conv->min_width - len) + 1];
	int			size;

	i = 0;
	size = (conv->min_width - len);
	tab[size] = '\0';
	if (!size)
		return (conv);
	else
	{
		while (i < size)
			tab[i++] = c;
		buffer(&*pf, tab, size);
	}
	conv->min_width = 0;
	return (conv);
}

void			no_conv(t_printf *pf, t_conv *conv)
{
	(conv->flag & ZERO && !(conv->flag & MINUS))
	? option_no_conv(&*pf, 1, '0', &*conv) : 0;
	conv->flag & SPACE ? option_no_conv(&*pf, 1, ' ', &*conv) : 0;
	conv->min_width > 1 && !(conv->flag & MINUS)
	? option_no_conv(&*pf, 1, ' ', &*conv) : 0;
	if (conv->min_width > 1 && conv->flag & MINUS)
	{
		(buffer(&*pf, &pf->format[pf->i], 1));
		option_no_conv(&*pf, 1, ' ', &*conv);
	}
	else
		(buffer(&*pf, &pf->format[pf->i], 1));
	pf->i++;
}
