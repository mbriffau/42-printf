/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:46:17 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_wildcard(t_printf *pf, t_conv *conv)
{
	int ptr;

	if (pf->format[pf->i] == '*')
	{
		ptr = va_arg(pf->ap, int);
		if (!(conv->flag & PREC_PARSE) && conv->flag & PRECISION)
		{
			if (ptr < 0)
				return (1);
			conv->precision = ptr;
			conv->flag += PREC_PARSE;
		}
		else
		{
			if (ptr < 0)
			{
				!(conv->flag & MINUS) ? conv->flag += MINUS : 0;
				ptr = -ptr;
			}
			conv->min_width = ptr;
		}
		return (1);
	}
	return (0);
}
