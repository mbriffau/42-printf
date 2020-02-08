/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:44:34 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conv_d_width_and_prec2(t_printf *pf, t_conv *conv, int len,
char *str)
{
	conv->before = 0;
	conv->flag & SPACE && !(conv->flag & PLUS) ?
	minwidth_decr_add_char_2_buff(&*pf, ' ', &*conv) : 0;
	conv->flag & PLUS ? conv->min_width-- : 0;
	if (conv->flag & ZERO && str[0] == '-')
	{
		str[0] = '0';
		buffer(&*pf, "-", 1);
		while (conv->min_width-- - len - 1)
			buffer(&*pf, "0", 1);
		buffer(&*pf, str, len);
		return (0);
	}
	while ((conv->min_width-- - conv->precision))
		buffer(&*pf, " ", 1);
	if (conv->flag & PLUS)
	{
		conv->before = 3;
		buffer(&*pf, "+", 1);
	}
	option_d(&*pf, conv->precision - len, '0', &*conv);
	return (0);
}

int				conv_d_width_and_prec(t_printf *pf, t_conv *conv, int len,
char *str)
{
	if (conv->flag & MODIFIER_HH)
		return (0);
	if (conv->min_width > conv->precision)
		return (conv_d_width_and_prec2(&*pf, conv, len, str));
	if (conv->min_width <= conv->precision)
	{
		conv->flag & PLUS ? buffer(&*pf, "+", 1) : 0;
		conv->flag & PLUS ? conv->min_width-- : 0;
		if (conv->flag & SPACE && !(conv->flag & PLUS))
			minwidth_decr_add_char_2_buff(&*pf, ' ', &*conv);
		conv->before = 3;
		option_d(&*pf, conv->precision - len, '0', &*conv);
	}
	return (0);
}

static int		conv_d3(t_printf *pf, t_conv *conv, int width_temp)
{
	if (conv->flag & MODIFIER_HH && !(conv->flag & MINUS))
		return (conv_d_hh_nominus(&*pf, conv, pf->str, ft_strlen(pf->str)));
	if (conv->flag & MINUS)
		return (conv_d_minus(&*pf, conv, width_temp, pf->str));
	((pf->str[0] == '-') && (conv->flag & MINUS)) ?
		((conv->min_width--)) : 0;
	if (conv->min_width && !conv->precision)
		return (conv_d_width_only(&*pf, conv, width_temp, pf->str));
	if (!conv->min_width && conv->precision && conv->flag & MINUS)
		return (0);
	if (!conv->min_width && conv->precision && !(conv->flag & MINUS))
		return (conv_d_prec_only(&*pf, conv, ft_strlen(pf->str), pf->str));
	if (conv->min_width && conv->precision)
		return (conv_d_width_and_prec(&*pf, conv, ft_strlen(pf->str), pf->str));
	return (1);
}

static int		conv_d2(t_printf *pf, t_conv *conv)
{
	if (!conv->min_width && !conv->precision && conv->flag & (SPACE + PLUS))
	{
		if (!(conv->flag & PLUS) && pf->str[0] != '-')
		{
			option(&*pf, ' ', 1);
			buffer(pf, pf->str, ft_strlen(pf->str));
			return (0);
		}
		if (pf->str[0] != '-')
		{
			option(&*pf, '+', 1);
			buffer(pf, pf->str, ft_strlen(pf->str));
			return (0);
		}
	}
	return (1);
}

void			conv_d(t_printf *pf, t_conv *conv)
{
	int				len;
	intmax_t		ptr;
	int				c;
	int				width_temp;

	c = 0;
	ptr = ptr_number_base(&*pf, conv->flag);
	pf->str = ft_itoa_printf((long long)ptr);
	len = ft_strlen(pf->str);
	if (!conv->precision && conv->flag & PRECISION && ptr == 0)
	{
		conv->flag & PLUS ? buffer(pf, "+", 1) : 0;
		option(&*pf, ' ', conv->min_width);
		return ;
	}
	if (!(conv_d2(&*pf, conv)))
		return ;
	width_temp = conv->min_width;
	if (!(conv_d3(&*pf, conv, width_temp)))
		return ;
	buffer(&*pf, pf->str, len);
	free(pf->str);
}
