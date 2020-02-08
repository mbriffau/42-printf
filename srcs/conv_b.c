/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:44:19 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_conv	*option_b(t_printf *pf, int print_size, char c, t_conv *conv)
{
	int			i;
	char		tab[(conv->min_width - print_size) + 1];
	int			size;

	size = (conv->min_width - print_size);
	i = 0;
	tab[size] = '\0';
	if (!size)
		return (conv);
	else
	{
		while (i < size)
			tab[i++] = c;
		buffer(&*pf, tab, size);
	}
	conv->min_width = 0;
	return (conv);
}

static void		call_option_b(t_printf *pf, t_conv *conv)
{
	if (conv->min_width > 8 && (conv->flag & ZERO) && !(conv->flag & MINUS))
		option_b(&*pf, 8, '0', &*conv);
	else if (conv->min_width > 8 && conv->flag & SPACE)
		option_b(&*pf, 8, ' ', &*conv);
	else if (conv->min_width > 8 && conv->flag & PLUS)
	{
		option_b(&*pf, 9, ' ', &*conv);
		buffer(&*pf, "+", 1);
	}
	else if (conv->min_width > 8 && !(conv->flag & MINUS))
		option_b(&*pf, 8, ' ', &*conv);
}

void			conv_b(t_printf *pf, t_conv *conv)
{
	unsigned int	ptr;
	char			*str;
	int				i;
	int				len;

	i = 0;
	ptr = va_arg(pf->ap, unsigned int);
	str = ft_itoa_base((long long)ptr, 2, 0);
	len = ft_strlen(str);
	call_option_b(&*pf, &*conv);
	while ((++i + len) <= 8)
		buffer(&*pf, "0", 1);
	buffer(&*pf, str, len);
	(conv->min_width > len && conv->flag & MINUS)
	? option_b(&*pf, 8, ' ', &*conv) : 0;
	free(str);
	return ;
}
