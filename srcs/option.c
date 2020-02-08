/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:46:00 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			option(t_printf *pf, int c, size_t n)
{
	char	s[n + 1];
	int		i;

	i = n;
	if (n)
	{
		s[n] = '\0';
		while (n)
			s[--n] = c;
		buffer(&*pf, s, i);
	}
	return (n);
}

static int	option_dbis_convbefore4(t_printf *pf, char *s)
{
	buffer(&*pf, "+", 1);
	buffer(&*pf, s, ft_strlen(s));
	return (0);
}

int			option_d(t_printf *pf, int n, char c, t_conv *conv)
{
	int		i;
	char	tab[n + 1];

	n ? i = 0 && tab[n] == '\0' : 0;
	if (!n)
		return (0);
	while (i < n)
		tab[i++] = c;
	if (conv->before == 4)
	{
		buffer(&*pf, tab, n);
		return (option_dbis_convbefore4(&*pf, pf->str));
	}
	(!(conv->before == 3) && conv->before && pf->str) ?
	buffer(&*pf, pf->str, ft_strlen(pf->str)) : 0;
	(!(conv->flag & MINUS) || (conv->flag & MINUS && conv->min_width >
	conv->precision) || conv->before == 3) ? buffer(&*pf, tab, n) : 0;
	((conv->flag & PLUS) && !(conv->flag & (ZERO + MINUS + MODIFIER_HH))
	&& (conv->flag & 0x26000000) && !(conv->before == 3)) ?
	buffer(&*pf, "+", 1) : 0;
	((conv->before == 0 && pf->str) || conv->before == 3) ?
	buffer(&*pf, &*pf->str, ft_strlen(pf->str)) : 0;
	((conv->flag & MINUS && !(conv->min_width > conv->precision))
	&& !(conv->before == 3)) ? buffer(&*pf, tab, n) : 0;
	return (0);
}
