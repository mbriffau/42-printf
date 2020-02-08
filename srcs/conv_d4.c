/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:44:47 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conv_d_minus_width_only(t_printf *pf, t_conv *conv, int len,
		char *str)
{
	if (conv->min_width < len)
		return (1);
	else if (conv->min_width > len)
	{
		(conv->flag & PLUS + MINUS + ZERO) ? conv->before = 1 : 0;
		(conv->flag & SPACE && !(conv->flag & PLUS) &&
		!(conv->flag & MODIFIER_HH)) ?
		minwidth_decr_add_char_2_buff(&*pf, ' ', &*conv) : 0;
		if (conv->flag & PLUS && !(conv->flag & ZERO) && !(conv->flag & SPACE)
			&& !(conv->flag & MODIFIER_HH))
		{
			minwidth_decr_add_char_2_buff(&*pf, '+', &*conv);
			conv->before = 1;
		}
		str[0] != '-' && conv->flag & PLUS && conv->flag & ZERO && !(conv->flag
		& MODIFIER_HH) ? buffer(&*pf, "+", 1) && conv->min_width-- : 0;
		option_d(&*pf, conv->min_width - len, ' ', conv);
		return (0);
	}
	(!(conv->flag & PLUS)) ? conv->before = 1 && option_d(&*pf, conv->min_width
	- len, ' ', conv) : 0;
	str = pf->str;
	return (0);
}

static int		conv_d_minus_width_and_prec(t_printf *pf, t_conv *conv,
int len, char *str)
{
	if (conv->min_width > conv->precision)
	{
		conv->before = 0;
		if (conv->flag & SPACE && !(conv->flag & PLUS)
		&& !(conv->flag & MODIFIER_HH))
			minwidth_decr_add_char_2_buff(&*pf, ' ', conv);
		if (conv->flag & PLUS && !(conv->flag & MODIFIER_HH))
			minwidth_decr_add_char_2_buff(&*pf, '+', conv);
		str[0] == '-' ? special_hhd_reverse_0_n_minus(&*pf, str, '-') : 0;
		option_d(&*pf, conv->precision - len, '0', conv);
		while ((conv->min_width-- - conv->precision))
			buffer(&*pf, " ", 1);
		return (0);
	}
	if (conv->min_width <= conv->precision)
	{
		str[0] == '-' ? special_hhd_reverse_0_n_minus(&*pf, str, '-') : 0;
		if (conv->flag & PLUS && !(conv->flag & MODIFIER_HH))
			minwidth_decr_add_char_2_buff(&*pf, '+', conv);
		if (conv->flag & SPACE && !(conv->flag & PLUS + MODIFIER_HH))
			minwidth_decr_add_char_2_buff(&*pf, ' ', conv);
		conv->before = 3;
		option_d(&*pf, conv->precision - len, '0', conv);
	}
	return (0);
}

static int		conv_d_minus3(t_printf *pf, t_conv *conv, int len, char *str)
{
	(conv->flag & SPACE && !(conv->flag & ZERO))
	|| (!(conv->flag & MODIFIER_HH) && conv->flag & SPACE
	&& conv->flag & ZERO && (!(conv->flag & PLUS))
	&& conv->min_width < len) ? buffer(&*pf, " ", 1) : 0;
	(conv->flag & PLUS && !(conv->flag & ZERO))
	|| (!(conv->flag & MODIFIER_HH) && conv->flag & PLUS
	&& conv->flag & ZERO && conv->min_width < len) ? buffer(&*pf, "+", 1) : 0;
	buffer(&*pf, str, len);
	return (0);
}

static int		conv_d_minus2(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!conv->min_width && !conv->precision)
		return (0);
	if (conv->min_width && !conv->precision)
	{
		if (!(conv_d_minus_width_only(pf, conv, len, str)))
			return (0);
	}
	if (!conv->min_width && conv->precision)
	{
		conv->before = 3;
		(conv->flag & SPACE && !(conv->flag & PLUS)
		&& !(conv->flag & MODIFIER_HH)) ? buffer(&*pf, " ", 1) : 0;
		(conv->flag & PLUS && !(conv->flag & MODIFIER_HH)) ?
		buffer(&*pf, "+", 1) : 0;
		(str[0] == '-') ? special_hhd_reverse_0_n_minus(pf, str, '-') : 0;
		option_d(&*pf, conv->precision - len, '0', conv);
		return (0);
	}
	if (conv->min_width && conv->precision)
		return (conv_d_minus_width_and_prec(pf, conv, len, str));
	conv_d_minus3(&*pf, conv, len, str);
	return (0);
}

int				conv_d_minus(t_printf *pf, t_conv *conv, int width_temp,
char *str)
{
	int		len;

	len = ft_strlen(str);
	if (!(conv_d_minus2(&*pf, conv, len, str)))
		return (0);
	if (conv->min_width > len || width_temp > len)
	{
		if (str[0] == '-')
		{
			width_temp--;
			if (conv->flag & PLUS && !(conv->flag & SPACE + ZERO))
				width_temp++;
		}
		if (conv->flag & MODIFIER_HH && !(conv->flag & SPACE + ZERO) &&
				conv->flag & PLUS && !(conv->precision))
		{
			buffer(&*pf, str, len);
			while (width_temp-- - len)
				buffer(&*pf, " ", 1);
		}
		return (0);
	}
	(conv->min_width < len && !(conv->flag & SPACE) && !(conv->flag & PLUS)
	&& !conv->precision) ? buffer(&*pf, str, len) : 0;
	return (0);
}
