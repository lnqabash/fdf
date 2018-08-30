/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:37:17 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/28 14:15:02 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	get_len(int n)
{
	size_t		count;

	count = 1;
	while (n /= 10)
	{
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	nbr;

	len = get_len(n);
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	s = ft_strnew(len);
	if (s == NULL)
		return (NULL);
	s[--len] = nbr % 10 + '0';
	while (nbr /= 10)
	{
		s[--len] = nbr % 10 + '0';
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
