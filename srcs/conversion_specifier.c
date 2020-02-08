/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:45:46 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			parse_type(char c)
{
	int ret;

	ret = 0;
	c == 'd' || c == 'D' || c == 'i' ? ret = TYPE_D : 0;
	c == 's' || c == 'S' ? ret = TYPE_S : 0;
	c == 'c' || c == 'C' ? ret = TYPE_C : 0;
	c == 'x' || c == 'X' ? ret = TYPE_X : 0;
	c == 'o' || c == 'O' ? ret = TYPE_O : 0;
	c == 'p' ? ret = TYPE_P : 0;
	c == 'u' || c == 'U' ? ret = TYPE_U : 0;
	c == 'b' ? ret = TYPE_B : 0;
	c == '%' ? ret = TYPE_PERCENT : 0;
	return (ret);
}

t_printf	*conversion_specifier(t_printf *pf, t_conv *conv)
{
	if (conv->flag & 0xFF800000)
	{
		conv->flag & TYPE_D ? conv_d(&*pf, &*conv) : 0;
		conv->flag & TYPE_S ? conv_s(&*pf, &*conv) : 0;
		conv->flag & TYPE_C ? conv_c(&*pf, &*conv) : 0;
		conv->flag & TYPE_P ? conv_p(&*pf, &*conv) : 0;
		conv->flag & TYPE_X ? conv_x(&*pf, &*conv) : 0;
		conv->flag & TYPE_O ? conv_x(&*pf, &*conv) : 0;
		conv->flag & TYPE_U ? conv_x(&*pf, &*conv) : 0;
		conv->flag & TYPE_B ? conv_b(&*pf, &*conv) : 0;
		conv->flag & TYPE_PERCENT ? conv_percent(&*pf, &*conv) : 0;
	}
	else if (!(conv->flag & 0xFF800000))
		(conv->flag & 0x1F) && conv->min_width ? no_conv(&*pf, &*conv) : 0;
	pf->i++;
	return (pf);
}
