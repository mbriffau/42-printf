/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:44:17 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/07 11:25:13 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			&& len > 0)
		len--;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (len != 0)
		new = (char *)malloc(len - i + 1);
	else
		new = (char *)malloc(1);
	if (new == NULL)
		return (NULL);
	j = 0;
	while (i < len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
