/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 21:28:19 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/17 12:24:01 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_conv	*option_percent(t_printf *pf, int len, char c, t_conv *conv)
{
	int		i;
	char	tab[(conv->min_width - len) + 1];
	int		size;

	size = (conv->min_width - len);
	i = 0;
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

void			conv_percent(t_printf *pf, t_conv *conv)
{
	char	c;

	c = '%';
	(conv->flag & ZERO && !(conv->flag & MINUS)) ?
	option_percent(&*pf, 1, '0', &*conv) : 0;
	conv->min_width > 1 && !(conv->flag & MINUS) ?
	option_percent(&*pf, 1, ' ', &*conv) : 0;
	if (conv->min_width > 1 && conv->flag & MINUS)
	{
		buffer(&*pf, &c, 1);
		option_percent(&*pf, 1, ' ', &*conv);
	}
	else
		buffer(&*pf, &c, 1);
}
