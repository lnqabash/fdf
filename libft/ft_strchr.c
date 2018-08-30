/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:13:54 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/13 15:42:07 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*src = s;
	int			index;

	index = 0;
	while ((src[index] != (char)c) && (src[index] != '\0'))
		index++;
	if (src[index] == (char)c)
		return ((char*)src + index);
	else if ((char)c == '\0')
		return ((char*)src);
	return (NULL);
}
