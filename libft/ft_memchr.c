/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:48:43 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/13 15:30:04 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*src;
	size_t			index;

	src = (const char *)s;
	index = 0;
	while (index < n)
	{
		if (src[index] == (char)c)
			return ((void *)(src + index));
		index++;
	}
	return (NULL);
}
