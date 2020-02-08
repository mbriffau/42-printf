/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:45:11 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_conv			option_p(t_printf *pf, int n, char c, t_conv *conv)
{
	int		i;
	char	tab[n + 1];
	int		len;

	len = ft_strlen(pf->str);
	i = 0;
	tab[n] = '\0';
	if (!n)
		return (*conv);
	while (i < n)
		tab[i++] = c;
	buffer(&*pf, tab, n);
	return (*conv);
}

int				print_p(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!(conv->flag & MINUS) && conv->min_width && (!(conv->precision))
			&& conv->min_width > len)
		option_p(&*pf, conv->min_width - len - 2, ' ', conv);
	buffer(&*pf, "0x", 2);
	if (conv->precision && conv->precision < conv->min_width
			&& conv->min_width > len)
		option_p(&*pf, conv->min_width - conv->precision - 2, '0', conv);
	if (conv->min_width <= conv->precision)
		option_p(&*pf, conv->precision - len, '0', conv);
	buffer(&*pf, str, len);
	return (0);
}

static int		conv_p_minus2(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!conv->min_width && !conv->precision)
		return (pf->i_buf);
	if (conv->min_width && !conv->precision)
	{
		if (conv->min_width < len)
		{
			print_p(&*pf, conv, len, str);
			return (0);
		}
		print_p(&*pf, conv, len, str);
		option_p(&*pf, conv->min_width - len - 2, ' ', conv);
		return (0);
	}
	if (!conv->min_width && conv->precision)
	{
		buffer(&*pf, "0x", 2);
		if (conv->precision > len)
		{
			(option_p(&*pf, conv->precision - len, '0', conv));
		}
		return (pf->i_buf);
	}
	return (1);
}

int				conv_p_minus(t_printf *pf, t_conv *conv, int len, char *str)
{
	if (!(conv_p_minus2(&*pf, conv, len, str)))
		return (0);
	if (conv->min_width && conv->precision)
	{
		if (conv->min_width <= conv->precision)
		{
			if (conv->precision > len)
				print_p(&*pf, conv, len, str);
			else
			{
				buffer(&*pf, "0x", 2);
				buffer(&*pf, str, len);
			}
			return (0);
		}
		if (conv->min_width > conv->precision)
		{
			print_p(&*pf, conv, len, str);
			if (conv->precision > len)
				option_p(&*pf, conv->min_width - conv->precision - 2,
						' ', conv);
			return (0);
		}
	}
	return (0);
}
