/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:55:18 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/08 09:46:55 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*de;
	char		*so;
	size_t		index;

	de = (char *)dst;
	so = (char *)src;
	index = 0;
	while (index < n)
	{
		de[index] = so[index];
		if ((unsigned char)so[index] == ((unsigned char)c))
			return ((char *)de + index + 1);
		index++;
	}
	return (NULL);
}
