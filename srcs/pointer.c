/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:41:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:46:27 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ptr_number_base(t_printf *pf, int f)
{
	intmax_t	ptr;

	ptr = 0;
	if (f & MODIFIER_H || f & MODIFIER_HH)
		ptr = (f & MODIFIER_HH ? (intmax_t)((char)va_arg(pf->ap, int))
			: (intmax_t)((short)va_arg(pf->ap, int)));
	else if (f & MODIFIER_L || f & MODIFIER_LL)
		ptr = (f & MODIFIER_LL ? va_arg(pf->ap, long long)
			: va_arg(pf->ap, long));
	else if (f & MODIFIER_Z)
		ptr = (intmax_t)(va_arg(pf->ap, size_t));
	else if (f & MODIFIER_J)
		ptr = va_arg(pf->ap, intmax_t);
	else
		ptr = va_arg(pf->ap, int);
	return (ptr);
}

uintmax_t	ptr_number(t_printf *pf, int f)
{
	uintmax_t	ptr;

	ptr = 0;
	if (f & MODIFIER_H || f & MODIFIER_HH)
	{
		ptr = (f & MODIFIER_HH ?
			(uintmax_t)((unsigned char)va_arg(pf->ap, unsigned int))
			: (uintmax_t)((unsigned short)va_arg(pf->ap, unsigned int)));
	}
	else if (f & MODIFIER_L || f & MODIFIER_LL)
		ptr = (f & MODIFIER_LL ?
			va_arg(pf->ap, unsigned long long)
			: va_arg(pf->ap, unsigned long));
	else if (f & MODIFIER_Z)
		ptr = (uintmax_t)(va_arg(pf->ap, ssize_t));
	else if (f & MODIFIER_J)
		ptr = va_arg(pf->ap, uintmax_t);
	else
		ptr = va_arg(pf->ap, unsigned int);
	return (ptr);
}

char		*ft_uitoa_pf(unsigned long n)
{
	int				i;
	unsigned long	a;
	char			*str;

	i = 1;
	a = n;
	while ((a = a / 10) > 0)
		i++;
	if (!(str = (char *)malloc((sizeof(char) * i) + 1)))
		return (0);
	ft_bzero(str, i + 1);
	str[i] = '\0';
	while (i-- >= 0)
	{
		str[i] = ((n % 10) + '0');
		n = n / 10;
	}
	return (str);
}

char		*ft_itoa_printf(long long n)
{
	int			i;
	long long	a;
	int			neg;
	char		*str;

	i = 1;
	neg = (n < 0) ? 1 : 0;
	if (n > 0)
		n = n * -1;
	a = n;
	while ((a = a / 10) < 0)
		i++;
	str = (char *)malloc((sizeof(char) * i) + neg + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, i + neg + 1);
	if (neg == 1)
		str[0] = '-';
	i -= 1 - neg;
	while (i-- >= neg)
	{
		str[i + 1] = (-(n % 10) + '0');
		n = n / 10;
	}
	return (str);
}
