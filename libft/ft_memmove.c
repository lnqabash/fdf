/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:23:02 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/13 15:31:47 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*est;
	char		*rc;
	size_t		index;

	est = (char *)dst;
	rc = (char *)src;
	if (est == src)
		return (est);
	if (est > rc)
	{
		while (len--)
			((char *)est)[len] = ((char *)rc)[len];
	}
	else
	{
		index = 0;
		while (index < len)
		{
			((char *)est)[index] = ((char *)rc)[index];
			index++;
		}
	}
	return (est);
}
