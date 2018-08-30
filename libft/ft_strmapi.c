/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:01:32 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/28 14:12:43 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;
	int				index;

	index = 0;
	if (s != NULL && f != NULL)
	{
		if ((fresh = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) != NULL)
		{
			i = 0;
			while (s[index] != '\0')
			{
				fresh[index] = f(i, s[index]);
				i++;
				index++;
			}
		}
		else
			return (NULL);
		fresh[index] = '\0';
		return (fresh);
	}
	return (NULL);
}
