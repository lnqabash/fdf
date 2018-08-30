/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:56:24 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/25 12:32:30 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr_copy;
	size_t	val;
	size_t	index;

	if (s == NULL)
		return (NULL);
	val = ft_strlen((char *)s);
	if ((ptr_copy = (char*)malloc(sizeof(char) * (len + 1)))
			!= NULL && (start < val))
	{
		index = 0;
		while ((s[start] != '\0') && (index < len))
		{
			ptr_copy[index] = s[start];
			index++;
			start++;
		}
		ptr_copy[index] = '\0';
		return (ptr_copy);
	}
	return (NULL);
}
