/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:44:29 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		count_wint(wint_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

static void		conv_c_wint(t_printf *pf, t_conv *conv)
{
	wint_t	c;
	int		len;

	if (MB_CUR_MAX == 1)
		exit(-1);
	c = va_arg(pf->ap, wint_t);
	if (!c)
	{
		conv->min_width > 1 && !(conv->flag & MINUS)
		? option_char(&*pf, 1, ' ', &*conv) : 0;
		buffer(*&pf, "\0", 1);
		return ;
	}
	len = count_wint(c);
	conv->min_width > len && conv->flag & ZERO && !(conv->flag & MINUS)
	? option_char(&*pf, len, '0', &*conv) : 0;
	conv->min_width > len && conv->flag & SPACE
	? option_char(&*pf, len, ' ', &*conv) : 0;
	conv->min_width > len && !(conv->flag & MINUS)
	? option_char(&*pf, len, ' ', &*conv) : 0;
	print_wint(&*pf, c);
	(conv->min_width > len && conv->flag & MINUS)
	? option_char(&*pf, len, ' ', &*conv) : 0;
}

void			conv_c(t_printf *pf, t_conv *conv)
{
	char	c;

	if (conv->flag & MODIFIER_L)
		conv_c_wint(&*pf, &*conv);
	else
	{
		c = va_arg(pf->ap, unsigned);
		if (!c)
		{
			conv->min_width > 1 && !(conv->flag & MINUS)
			? option_char(&*pf, 1, ' ', &*conv) : 0;
			buffer(*&pf, "\0", 1);
			return ;
		}
		(conv->flag & ZERO && !(conv->flag & MINUS))
		? option_char(&*pf, 1, '0', &*conv) : 0;
		conv->flag & SPACE ? option_char(&*pf, 1, ' ', &*conv) : 0;
		conv->min_width > 1 && !(conv->flag & MINUS)
		? option_char(&*pf, 1, ' ', &*conv) : 0;
		buffer(&*pf, ((char*)&c), 1);
		(conv->min_width > 1 && conv->flag & MINUS)
		? option_char(&*pf, 1, ' ', &*conv) : 0;
	}
	return ;
}
