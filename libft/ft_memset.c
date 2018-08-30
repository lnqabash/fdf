/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:53:13 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/13 15:31:00 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy;
	size_t			index;

	copy = b;
	index = 0;
	while (index < len)
	{
		copy[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
