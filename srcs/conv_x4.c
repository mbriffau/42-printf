/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/22 05:17:49 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*ft_str_tolower(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}

static int			fill_tab_with_c(t_printf *pf, char *tab, char c)
{
	int i;

	i = 0;
	while (i < pf->n)
		tab[i++] = c;
	buffer(&*pf, tab, i);
	return (pf->i_buf);
}

static t_conv		option_x3(t_printf *pf, char *tab,
		char c, t_conv *conv)
{
	if (!(conv->flag & MINUS) || (conv->flag & MINUS &&
				conv->min_width > conv->precision) || conv->before == 3)
	{
		(conv->flag & SHARP && conv->ox == 2) ? buffer(&*pf, "0x", 2) : 0;
		fill_tab_with_c(&*pf, tab, c);
	}
	(((conv->flag & PLUS) && !(conv->flag & ZERO) && !(conv->flag & MINUS)
	&& (conv->flag & (TYPE_D + TYPE_U + TYPE_O)) && !(conv->before == 3)
	&& !(conv->flag & MODIFIER_HH))) ? buffer(&*pf, "+", 1) : 0;
	return (*conv);
}

static t_conv		option_x2(t_printf *pf, int n, char c, t_conv *conv)
{
	char	tab[n + 1];
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(pf->str);
	tab[n] = '\0';
	if (!(conv->before == 3) && conv->before && pf->str)
	{
		(conv->ox == 1) ? buffer(&*pf, "0x", 2) : 0;
		conv->flag & TYPE_O && conv->flag & SHARP ? buffer(&*pf, "0", 1)
			&& conv->min_width-- : 0;
		buffer(&*pf, pf->str, len);
	}
	option_x3(&*pf, tab, c, conv);
	if ((conv->before == 0 && pf->str) || conv->before == 3)
	{
		(conv->ox == 1) ? buffer(&*pf, "0x", 2) : 0;
		conv->flag & TYPE_O && conv->flag & SHARP && conv->min_width ?
			buffer(&*pf, "0", 1) : 0;
		buffer(&*pf, &*pf->str, len);
	}
	((conv->flag & MINUS && !(conv->min_width > conv->precision))
	&& !(conv->before == 3)) ? fill_tab_with_c(&*pf, tab, c) : 0;
	return (*conv);
}

t_conv				option_x(t_printf *pf, int n, char c, t_conv *conv)
{
	int		i;
	char	array[n + 1];
	int		len;

	ft_bzero(array, n + 1);
	len = ft_strlen(pf->str);
	i = 0;
	pf->n = n;
	if (!n)
		return (*conv);
	if (conv->before == 4)
	{
		if (conv->flag & SHARP)
			pf->n--;
		fill_tab_with_c(&*pf, array, c);
		buffer(&*pf, " ", 1);
		if (conv->flag & SHARP)
			buffer(&*pf, "0x", 2);
		buffer(&*pf, pf->str, len);
		return (*conv);
	}
	option_x2(&*pf, pf->n, c, conv);
	return (*conv);
}
