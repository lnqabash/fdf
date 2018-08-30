/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:14:43 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/14 12:00:43 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int h;
	int n;
	int	len;

	h = 0;
	n = 0;
	len = (int)ft_strlen(needle);
	if (!len)
		return ((char*)haystack);
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n])
		{
			if (n == (int)(ft_strlen(needle) - 1))
				return ((char*)haystack + h);
			n++;
		}
		h++;
	}
	return (NULL);
}
