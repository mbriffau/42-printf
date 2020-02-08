/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:44:14 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		text_color(t_printf *pf, char *color)
{
	int i;
	int len;

	i = 0;
	len = 2;
	color += 1;
	(*color == '!') ? (i += 40) && (color += 1) : (i += 30);
	ft_strcmp("black}", color) == 0 ? i += 0 : 0;
	ft_strcmp("red}", color) == 0 ? i += 1 : 0;
	ft_strcmp("green}", color) == 0 ? i += 2 : 0;
	ft_strcmp("yellow}", color) == 0 ? i += 3 : 0;
	ft_strcmp("blue}", color) == 0 ? i += 4 : 0;
	ft_strcmp("violet}", color) == 0 ? i += 5 : 0;
	ft_strcmp("cyan}", color) == 0 ? i += 6 : 0;
	ft_strcmp("white}", color) == 0 ? i += 7 : 0;
	if (ft_strcmp("eoc}", color) == 0)
	{
		(i = 0);
		(len = 1);
	}
	buffer(&*pf, ft_itoa(i), len);
	pf->subtract_buffer += len;
}

static void		parse_formatting(t_printf *pf, char *param)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	param += 1;
	(*param == '!') ? (i += 20) && (param += 1) && len++ : 0;
	ft_strcmp("eof}", param) == 0 ? i = 0 : 0;
	ft_strcmp("bold}", param) == 0 ? i += 1 : 0;
	ft_strcmp("underline}", param) == 0 ? i += 4 : 0;
	ft_strcmp("binking}", param) == 0 ? i += 5 : 0;
	ft_strcmp("highlight}", param) == 0 ? i += 7 : 0;
	buffer(&*pf, ft_itoa(i), len);
	buffer(&*pf, ";", 1);
	pf->subtract_buffer += len + 1;
}

static int		searchin(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j])
			{
				i++;
				j++;
				if (!s1[i])
					return (j);
			}
			i = 0;
		}
		j++;
	}
	return (0);
}

t_printf		parsing_color(t_printf *pf)
{
	int		i;
	int		len;
	char	*color;
	int		ret;

	i = pf->i;
	if ((len = ft_strlen_c(&pf->format[i], '}')))
	{
		len++;
		color = ft_strsub(pf->format, i, len);
		if ((ret = searchin(color, "{eoc}{black}{red}{blue}{green}{yellow5}\
		{violet}{cyan}{white}{!black}{!red}{!blue}{!green}{!yellow}\
		{!violet}{!cyan}{!white}{bold}{underline}{!bold}{!underline}{eof}")))
		{
			buffer(&*pf, "\033[", 2);
			if (ret > 126)
				parse_formatting(&*pf, color);
			else
				text_color(&*pf, color);
			buffer(&*pf, "m", 1);
			pf->i += len;
			pf->subtract_buffer += 3;
		}
	}
	return (*pf);
}
