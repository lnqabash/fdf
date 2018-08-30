/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:48:23 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/10 09:56:17 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ptr;
	int		index;
	int		count;

	index = 0;
	ptr = (char *)s1;
	while (ptr[index] != '\0')
		index++;
	count = 0;
	while (s2[count])
	{
		ptr[index] = s2[count];
		index++;
		count++;
	}
	ptr[index] = '\0';
	return (ptr);
}
