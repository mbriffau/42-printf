/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:44:43 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conv_d_hh_nominus_width_and_prec(t_printf *pf, t_conv *conv,
char *str, int len)
{
	if (conv->min_width > conv->precision)
	{
		conv->before = 0;
		conv->flag & ZERO && !(conv->flag & PLUS) ? conv->min_width-- : 0;
		if (conv->flag & SPACE)
		{
			conv->min_width--;
			conv->flag & PLUS + ZERO ? buffer(&*pf, " ", 1) : 0;
		}
		conv->flag & PLUS ? conv->min_width-- : 0;
		while ((conv->min_width-- - conv->precision))
			buffer(&*pf, " ", 1);
		conv->flag & PLUS && str[0] != '-' ? conv->before = 3
		&& buffer(&*pf, "+", 1) : 0;
		str[0] == '-' ? special_hhd_reverse_0_n_minus(&*pf, str, '-') : 0;
		option_d(&*pf, conv->precision - len, '0', conv);
		return (0);
	}
	if (conv->min_width <= conv->precision)
	{
		str[0] == '-' ? special_hhd_reverse_0_n_minus(&*pf, str, '-') : 0;
		conv->before = 3;
		option_d(&*pf, conv->precision - len, '0', conv);
	}
	return (0);
}

static int		conv_d_hh_nominus_width_only2(t_printf *pf, t_conv *conv,
char *str, int len)
{
	if (conv->flag & PLUS && !(conv->flag & ZERO + MODIFIER_HH))
		conv->min_width--;
	else if (str[0] != '-' && conv->flag & PLUS && conv->flag
	& ZERO && !(conv->flag & MODIFIER_HH))
	{
		buffer(&*pf, "+", 1);
		option_d(&*pf, conv->min_width - 1 - len, '0', conv);
		return (0);
	}
	else if (conv->flag & ZERO)
	{
		if (str[0] == '-')
		{
			str[0] = '0';
			return (add_char_and_string_2_buff(&*pf, '-', str, len));
		}
		option_d(&*pf, conv->min_width - len, '0', conv);
		return (0);
	}
	option_d(&*pf, conv->min_width - len, ' ', conv);
	return (0);
}

static int		conv_d_hh_nominus_width_only(t_printf *pf, t_conv *conv,
char *str, int len)
{
	if (conv->min_width < len)
	{
		if (conv->flag & PLUS && str[0] != '-')
			return (add_char_and_string_2_buff(&*pf, '+', str, len));
		if (conv->flag & SPACE && !(conv->flag & ZERO))
			return (add_char_and_string_2_buff(&*pf, ' ', str, len));
		buffer(&*pf, str, len);
	}
	if (conv->min_width >= len)
		conv_d_hh_nominus_width_only2(&*pf, conv, str, len);
	return (0);
}

int				conv_d_hh_nominus(t_printf *pf, t_conv *conv,
char *str, int len)
{
	if (conv->min_width && !conv->precision)
		return (conv_d_hh_nominus_width_only(pf, conv, str, len));
	if (!conv->min_width && conv->precision)
	{
		conv->before = 3;
		if (conv->flag & SPACE && !(conv->flag & PLUS) &&
		!(conv->flag & MODIFIER_HH))
			buffer(&*pf, " ", 1);
		if (conv->flag & PLUS && !(conv->flag & MODIFIER_HH))
			buffer(&*pf, "+", 1);
		if (str[0] == '-')
			special_hhd_reverse_0_n_minus(pf, str, '-');
		option_d(&*pf, conv->precision - len, '0', conv);
		return (0);
	}
	if (conv->min_width && conv->precision)
		return (conv_d_hh_nominus_width_and_prec(pf, conv, str, len));
	buffer(&*pf, str, len);
	return (0);
}
