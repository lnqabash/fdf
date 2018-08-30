/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:59:28 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/07 12:49:41 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;
	int		index;
	size_t	count;

	ptr = (char *)s1;
	index = 0;
	while (ptr[index] != '\0')
		index++;
	count = 0;
	while (s2[count] && (count < n))
	{
		ptr[index] = s2[count];
		index++;
		count++;
	}
	ptr[index] = '\0';
	return (ptr);
}
