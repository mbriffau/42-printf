/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:18:05 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/07 18:37:09 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;

	if (nb > 0 && nb <= 12)
	{
		i = nb;
		while (nb > 1)
		{
			i *= (nb - 1);
			nb -= 1;
		}
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
	return (i);
}
