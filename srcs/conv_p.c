/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:45:02 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		going_for_option(t_printf *pf, t_conv *conv)
{
	buffer(&*pf, "0x", 2);
	if (conv->precision > pf->len)
		option_p(&*pf, conv->precision - pf->len, '0', conv);
	buffer(&*pf, pf->str, pf->len);
	return (pf->i_buf);
}

static int		conv_p3(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (conv->flag & MINUS)
	{
		(conv_p_minus(&*pf, conv, len, str));
		if ((conv->precision && conv->min_width) ||
				(conv->min_width && !conv->precision))
			return (0);
	}
	if (conv->min_width && !conv->precision)
	{
		if (conv->min_width < len)
			return (print_p(&*pf, conv, len, str));
		if (conv->min_width >= len)
		{
			if (conv->flag & ZERO)
			{
				buffer(&*pf, "0x", 2);
				option_p(&*pf, conv->min_width - len - 2, '0', conv);
				buffer(&*pf, str, len);
				return (0);
			}
			print_p(&*pf, conv, len, str);
			return (0);
		}
	}
	return (1);
}

static int		conv_p2(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!(conv->min_width) && !(conv->precision))
	{
		buffer(&*pf, "0x", 2);
		buffer(&*pf, str, len);
		return (0);
	}
	if (!(conv_p3(&*pf, conv, len, str)))
		return (0);
	if (conv->min_width && conv->precision)
	{
		if (conv->min_width > len && conv->min_width > conv->precision)
		{
			option_p(&*pf, conv->min_width - conv->precision - 2, ' ', conv);
			buffer(&*pf, "0x", 2);
			option_p(&*pf, conv->min_width - conv->precision - len, '0', conv);
			buffer(&*pf, str, len);
			return (0);
		}
	}
	if (!conv->min_width && conv->precision && conv->flag & MINUS)
	{
		buffer(&*pf, str, len);
		return (0);
	}
	return (1);
}

int				conv_p(t_printf *pf, t_conv *conv)
{
	void	*pointer;
	char	*str;
	int		i;
	int		len;

	i = 0;
	conv->ox = 1;
	pointer = va_arg(pf->ap, void *);
	str = ft_itoa_base((long long)pointer, 16, 0);
	pf->str = str;
	len = ft_strlen(str);
	pf->len = len;
	(ft_isalpha(str[0])) ? str[0] = ft_tolower((int)str[0]) : 0;
	while (str[i++])
		(ft_isalpha(str[i])) ? str[i] = ft_tolower((int)str[i]) : 0;
	if (!(conv_p2(&*pf, conv, len, str)))
		return (pf->i_buf);
	if (!conv->min_width && conv->precision && !(conv->flag & MINUS))
		return (going_for_option(&*pf, conv));
	if (conv->min_width && conv->precision)
		return (going_for_option(&*pf, conv));
	buffer(&*pf, str, len);
	free(str);
	return (0);
}
