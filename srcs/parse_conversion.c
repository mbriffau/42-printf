/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:46:03 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_conv	*parse_flags(t_conv *conv, char *s, int *i)
{
	while (ft_strchr("#0-+ ", s[*i]))
	{
		s[*i] == '-' && !(conv->flag & MINUS) ? conv->flag += MINUS : 0;
		s[*i] == '+' && !(conv->flag & PLUS) ? conv->flag += PLUS : 0;
		s[*i] == '#' && !(conv->flag & SHARP) ? conv->flag += SHARP : 0;
		s[*i] == '0' && !(conv->flag & ZERO) ? conv->flag += ZERO : 0;
		s[*i] == ' ' && !(conv->flag & SPACE) ? conv->flag += SPACE : 0;
		if (s[*i] == '\0')
			break ;
		*i += 1;
	}
	return (conv);
}

static t_conv	*parse_precision(t_printf *pf, t_conv *conv)
{
	!(conv->flag & PRECISION) ? conv->flag += PRECISION : 0;
	parse_wildcard(&*pf, &*conv) ? pf->i++ : 0;
	if (ft_isdigit(pf->format[pf->i]))
	{
		conv->precision = ft_atoi(&pf->format[pf->i]);
		while (ft_isdigit(pf->format[pf->i]))
			pf->i++;
		if (!pf->format[pf->i])
			ft_error_pf(INFO, "Invalid format. (After Precision)");
		conv->flag & PREC_PARSE ? 0 : (conv->flag += PREC_PARSE);
		parse_wildcard(&*pf, &*conv) ? pf->i++ : 0;
	}
	return (conv);
}

static int		overwrite_modifier(int *f)
{
	if (*f & 0x7E0)
	{
		if (*f & MODIFIER_H)
			*f -= MODIFIER_H;
		else if (*f & MODIFIER_HH)
			*f -= MODIFIER_HH;
		else if (*f & MODIFIER_L)
			*f -= MODIFIER_L;
		else if (*f & MODIFIER_LL)
			*f -= MODIFIER_LL;
		else if (*f & MODIFIER_J)
			*f -= MODIFIER_J;
		else if (*f & MODIFIER_Z)
			*f -= MODIFIER_Z;
	}
	return (*f);
}

static void		parse_modifier(int *i, int *f, char *s)
{
	if (ft_strchr("X", s[*i]))
		!(*f & MODIFIER_X) ? (*f += MODIFIER_X) : 0;
	else if (ft_strchr("F", s[*i]))
		!(*f & MODIFIER_F) ? (*f += MODIFIER_F) && *i++ : 0;
	while (ft_strchr("hljzCSDUO", s[*i]))
	{
		overwrite_modifier(&*f);
		if (ft_strchr("CSDUO", s[*i]))
		{
			*f += MODIFIER_L;
			break ;
		}
		if (s[*i] == 'h')
			(s[*i + 1] == 'h') ? (*f += MODIFIER_HH) && (*i += 1)
		: (*f += MODIFIER_H);
		else if (s[*i] == 'l')
			(s[*i + 1] == 'l') ? (*f += MODIFIER_LL) && (*i += 1)
		: (*f += MODIFIER_L);
		(s[*i] == 'j') ? (*f += MODIFIER_J) : 0;
		(s[*i] == 'z') ? (*f += MODIFIER_Z) : 0;
		*i += 1;
	}
}

t_printf		*parse_conversion(t_printf *pf)
{
	t_conv		*conv;

	conv = init_conv();
	parse_flags(&*conv, pf->format, &pf->i);
	parse_wildcard(&*pf, &*conv) ? pf->i++ : 0;
	if (ft_isdigit(pf->format[pf->i]))
		conv->min_width = ft_atoi(&pf->format[pf->i]);
	parse_wildcard(&*pf, &*conv) ? pf->i++ : 0;
	while (ft_isdigit(pf->format[pf->i]))
		pf->i++;
	if (!(pf->format))
		ft_error_pf(INFO, "error_parse_minimal_width");
	(pf->format[pf->i] == '.' ? (pf->i++) && parse_precision(&*pf, &*conv) : 0);
	parse_modifier(&pf->i, &conv->flag, pf->format);
	(!pf->format[pf->i]) ? ft_error_pf(INFO, "error_format_type") : 0;
	conv->flag += parse_type(pf->format[pf->i]);
	conversion_specifier(&*pf, &*conv);
	free(conv);
	return (pf);
}
