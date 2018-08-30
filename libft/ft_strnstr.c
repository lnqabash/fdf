/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:36:46 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/15 17:14:12 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	if (haystack[m] == '\0' && needle[n] == '\0')
		return (NULL);
	else if (needle[n] == '\0')
		return ((char*)haystack);
	while (haystack[m] && (m < len))
	{
		n = 0;
		while (needle[n] && haystack[m + n] == needle[n] && m + n < len)
			n++;
		if (needle[n] == '\0')
			return ((char *)haystack + m);
		m++;
	}
	return (NULL);
}
