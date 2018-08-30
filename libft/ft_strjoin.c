/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:24:18 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/22 13:01:38 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		index;
	int		count;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr)
	{
		index = 0;
		while (s1[index] != '\0')
		{
			ptr[index] = s1[index];
			index++;
		}
		count = 0;
		while (s2[count] != '\0')
		{
			ptr[index + count] = s2[count];
			count++;
		}
		ptr[index + count] = '\0';
		return (ptr);
	}
	return (NULL);
}
