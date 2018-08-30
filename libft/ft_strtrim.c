/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:14:26 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/15 10:47:34 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		index;
	int		count;
	int		i;

	if (s != NULL)
	{
		index = 0;
		while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
			index++;
		count = ft_strlen(s) - 1;
		while ((s[count] == ' ' || s[count] == '\n' || s[count] == '\t')
				&& (index < count))
			count--;
		str = ft_strnew(count - index + 1);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (index <= count)
			str[i++] = s[index++];
		str[count + 1] = '\0';
		return (str);
	}
	return (NULL);
}
