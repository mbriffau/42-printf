/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/22 05:18:29 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf		*add_0x(t_printf *pf, t_conv *conv)
{
	if (conv->flag & MODIFIER_X)
	{
		buffer(&*pf, "0X", 2);
		return (pf);
	}
	buffer(&*pf, "0x", 2);
	return (pf);
}

static int		conv_x_width_only3(t_printf *pf, t_conv *conv, int len,
		char *str)
{
	if (str[0] == '-')
	{
		str[0] = '0';
		(add_char_and_string_2_buff(&*pf, '-', str, len));
		return (0);
	}
	(conv->flag & SHARP && conv->flag & TYPE_X &&
	ft_strncmp(pf->str, "0", 1)) ? (buffer(&*pf, "0x", 2))
		&& (conv->min_width = conv->min_width - 2) : 0;
	conv->flag & TYPE_O && conv->flag & SHARP ? conv->min_width-- : 0;
	!(conv->flag & TYPE_O) || (conv->min_width && conv->flag & ZERO &&
			!(conv->flag & PRECISION)) ?
		option_x(&*pf, conv->min_width - len, '0', &*conv) :
		option_x(&*pf, conv->min_width - len, ' ', &*conv);
	return (0);
	return (1);
}

static int		conv_x_width_only2(t_printf *pf, t_conv *conv, int len,
		char *str)
{
	if (conv->flag & PLUS && conv->flag & ZERO && !(conv->flag & MODIFIER_HH))
	{
		(conv->flag & SHARP) ? (buffer(&*pf, "0x", 2))
			&& (conv->min_width = conv->min_width - 2) : 0;
		option_x(&*pf, conv->min_width - len, '0', &*conv);
		return (0);
	}
	else if (conv->flag & ZERO)
	{
		if (!(conv_x_width_only3(&*pf, conv, len, str)))
			return (0);
	}
	if (conv->flag & MODIFIER_HH)
	{
		while (conv->min_width-- - len)
			buffer(&*pf, " ", 1);
		buffer(&*pf, str, len);
		return (0);
	}
	return (1);
}

int				conv_x_width_only(t_printf *pf, t_conv *conv, int len,
		char *str)
{
	if (conv->min_width && !conv->precision)
	{
		if (conv->min_width < len)
		{
			if (conv->flag & SHARP && conv->flag & TYPE_X
					&& !(conv->flag & MINUS))
				add_0x(&*pf, &*conv);
			buffer(&*pf, str, len);
			return (0);
		}
		if (conv->min_width >= len || conv->width_temp >= len)
		{
			(conv->flag & PLUS && !(conv->flag & ZERO + MODIFIER_HH + SHARP))
				? conv->min_width-- : 0;
			if (!(conv_x_width_only2(&*pf, conv, len, str)))
				return (0);
			(conv->flag & PLUS && !(conv->flag & ZERO) && !(conv->flag & SPACE))
				? conv->before = 4 : 0;
			(conv->flag & SHARP && conv->flag & TYPE_X) ? (conv->ox = 1)
				&& (conv->min_width = conv->min_width - 2) : 0;
			option_x(&*pf, conv->min_width - len, ' ', &*conv);
			return (0);
		}
	}
	return (1);
}
