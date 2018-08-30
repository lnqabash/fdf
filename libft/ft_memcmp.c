/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:39:25 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/07 16:08:59 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*m = (char*)s1;
	const char	*l = (char*)s2;
	size_t		index;

	index = 0;
	while (index < n)
	{
		if (m[index] == l[index])
			index++;
		else if (m[index] != l[index])
			return ((unsigned char)m[index] - (unsigned char)l[index]);
	}
	return (0);
}
