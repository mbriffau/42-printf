/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:45:21 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			print_wstring(t_printf *pf, wchar_t *wstr, int n)
{
	while (n--)
		print_wint(&*pf, *wstr++);
}

static void			conv_s_base(t_printf *pf, t_conv *conv, void *str, int len)
{
	int	free_or_not;

	free_or_not = 0;
	if (str == NULL)
	{
		(str = ft_strdup("(null)"));
		free_or_not = 1;
	}
	len = ft_strlen(str);
	if (conv->flag & PRECISION && conv->precision < len)
		len = conv->precision;
	if (conv->min_width > len && (conv->flag & ZERO) && !(conv->flag & MINUS))
		option_char(&*pf, len, '0', &*conv);
	else if (conv->min_width > len && (conv->flag & SPACE
		|| !(conv->flag & MINUS)))
		option_char(&*pf, len, ' ', &*conv);
	buffer(&*pf, str, len);
	(conv->min_width > len && conv->flag & MINUS)
	? option_char(&*pf, len, ' ', &*conv) : 0;
	free_or_not ? free(str) : 0;
}

static int			size_wchar(wchar_t *s, int max)
{
	int		add;
	int		i;

	add = 0;
	i = 0;
	while (add < max)
	{
		if (s[i] <= 0x7F)
			add += 1;
		else if (s[i] <= 0x7FF)
			add += 2;
		else if (s[i] <= 0xFFFF)
			add += 3;
		else if (s[i] <= 0x10FFFF)
			add += 4;
		if (add <= max)
			i++;
	}
	return (i);
}

static void			conv_s_wchar(t_printf *pf, t_conv *conv, wchar_t *str)
{
	int		width;
	int		len;

	len = count_wchars(conv, str, ft_wstrlen(str));
	if (conv->flag & PRECISION && conv->precision < len)
		len = conv->precision;
	if (conv->min_width > len && (conv->flag & ZERO) && !(conv->flag & MINUS))
		option_char(&*pf, len, '0', &*conv);
	else if (conv->min_width > len && (conv->flag & SPACE
		|| !(conv->flag & MINUS)))
		option_char(&*pf, len, ' ', &*conv);
	if (conv->flag & PRECISION && conv->precision < ft_wstrlen(str))
		width = size_wchar(str, conv->precision);
	else
		width = ft_wstrlen(str);
	print_wstring(&*pf, str, width);
	(conv->min_width > len && conv->flag & MINUS)
	? option_char(&*pf, len, ' ', &*conv) : 0;
}

/*
**	if (conv->flag & MODIFIER_F)
**	{
**		conv_s_file(&*pf);
**		return ;
**	}
*/

void				conv_s(t_printf *pf, t_conv *conv)
{
	void	*str;

	if (conv->flag & MODIFIER_L)
	{
		str = va_arg(pf->ap, wchar_t *);
		!(MB_CUR_MAX > 1) ? exit(-1) : 0;
		if (str == NULL)
			conv_s_base(&*pf, &*conv, str, 0);
		else
			conv_s_wchar(&*pf, &*conv, str);
	}
	else
	{
		str = va_arg(pf->ap, unsigned char *);
		conv_s_base(&*pf, &*conv, str, 0);
	}
}
