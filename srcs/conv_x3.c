/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/22 05:16:25 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conv_x_minus_width_sup_len(t_printf *pf, t_conv *conv, int len)
{
	if (conv->min_width > len)
	{
		(conv->flag & SHARP && !(conv->flag & TYPE_O)) ?
			(conv->min_width = conv->min_width - 2)
		&& (buffer(&*pf, "0x", 2)) : 0;
		if (conv->flag & PLUS && !(conv->flag & ZERO) && !(conv->flag & SPACE))
		{
			conv->before = 1;
			option_x(&*pf, conv->min_width - len, ' ', conv);
			return (0);
		}
		(conv->flag & PLUS && !(conv->flag & ZERO)) ? conv->min_width-- : 0;
		if ((conv->flag & PLUS && conv->flag & ZERO && !(conv->flag & MODIFIER_HH)) || (conv->flag & ZERO))
		{
			conv->before = 1;
			option_x(&*pf, conv->min_width - len, ' ', conv);
			return (0);
		}
	}
	return (1);
}

static int		conv_x_minus_width_only(t_printf *pf, t_conv *conv, int len)
{
	if (conv->min_width && !conv->precision)
	{
		if (conv->min_width < len)
		{
			(conv->flag & SHARP) ? buffer(&*pf, "0x", 2) : 0;
			return (0);
		}
		if (!(conv_x_minus_width_sup_len(&*pf, conv, len)))
			return (0);
		if (!(conv->flag & PLUS))
		{
			conv->before = 1;
			option_x(&*pf, conv->min_width - len, ' ', conv);
			return (0);
		}
		option_x(&*pf, conv->min_width - len, ' ', conv);
		return (0);
	}
	return (1);
}

static int		conv_x_minus_width_and_prec(t_printf *pf, t_conv *conv,
int len, char *str)
{
	if (conv->min_width && conv->precision)
	{
		if (conv->min_width > conv->precision)
		{
			(conv->flag & SHARP) ? (buffer(&*pf, "0x", 2))
			&& (conv->min_width = conv->min_width - 2) : 0;
			conv->before = 0;
			(str[0] == '-') ? special_hhd_reverse_0_n_minus(&*pf, str, '-') : 0;
			option_x(&*pf, conv->precision - len, '0', conv);
			while ((conv->min_width-- - conv->precision))
				buffer(&*pf, " ", 1);
			return (0);
		}
		if (conv->min_width <= conv->precision)
			(str[0] == '-') ? special_hhd_reverse_0_n_minus(&*pf, str, '-') : 0;
		(conv->flag & SHARP) ? (buffer(&*pf, "0x", 2))
		&& (conv->min_width = conv->min_width - 2) : 0;
		conv->before = 3;
		option_x(&*pf, conv->precision - len, '0', conv);
		return (0);
	}
	return (1);
}

static int		conv_x_minus2(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!conv->min_width && !conv->precision)
		return (pf->i_buf);
	if (!(conv_x_minus_width_only(&*pf, conv, len)))
		return (pf->i_buf);
	if (!conv->min_width && conv->precision)
	{
		if (conv->flag & SHARP)
			buffer(&*pf, "0x", 2);
		conv->before = 3;
		if (str[0] == '-')
		{
			special_hhd_reverse_0_n_minus(pf, str, '-');
		}
		option_x(&*pf, conv->precision - len, '0', conv);
		return (pf->i_buf);
	}
	if (!(conv_x_minus_width_and_prec(&*pf, conv, len, str)))
		return (pf->i_buf);
	buffer(&*pf, str, len);
	return (0);
}

int				conv_x_minus(t_printf *pf, t_conv *conv, char *str, int len)
{
	if (conv->flag & MINUS)
	{
		(conv_x_minus2(&*pf, conv, len, str));
		if (conv->min_width > len || conv->width_temp > len)
		{
			if (str[0] == '-')
			{
				conv->width_temp--;
				(conv->flag & PLUS && !(conv->flag & SPACE + ZERO))
				? conv->width_temp++ : 0;
			}
			return (0);
		}
		if (conv->min_width < len && !(conv->flag & SPACE)
		&& !(conv->flag & PLUS) && !conv->precision)
		{
			buffer(&*pf, str, len);
			return (0);
		}
	}
	return (1);
}
