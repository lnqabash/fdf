/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:06:52 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/14 11:29:00 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr_copy;
	int		index;
	int		count;

	if (s != NULL && f != NULL)
	{
		count = ft_strlen((char *)s);
		if ((ptr_copy = (char *)malloc(sizeof(char) * (count + 1))) != NULL)
		{
			index = 0;
			while (s[index] != 0)
			{
				ptr_copy[index] = f(s[index]);
				index++;
			}
		}
		else
		{
			return (NULL);
		}
		ptr_copy[index] = '\0';
		return (ptr_copy);
	}
	return (NULL);
}
