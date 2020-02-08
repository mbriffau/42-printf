/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 00:52:04 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/19 00:28:00 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_error_pf(char *file, char *func, int line, char *s)
{
	ft_putstr("\033[1;37m----- \033[1;31mERROR\033[1;37m ----------\033[0m\n");
	ft_putstr("\033[1;37mfile\033[0m		: ");
	ft_putstr(file);
	ft_putstr("\n\033[1;37mfunction\033[0m	: ");
	ft_putstr(func);
	ft_putstr("\n\033[1;37mline\033[0m		: (");
	ft_putnbr(line);
	ft_putstr(")\n\033[1;37merror message\033[0m	: ");
	ft_putstr(s);
	ft_putstr("\n\033[1;37m----------------------\033[0m");
	exit(-1);
}
