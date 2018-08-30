/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 08:37:05 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/15 08:09:44 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	char	*tmp_dst;
	char	*tmp_src;

	i = 0;
	tmp_dst = dst;
	tmp_src = (char *)src;
	i = ft_strlen(tmp_dst);
	j = ft_strlen(tmp_src);
	if (i > dstsize)
		return (j + dstsize);
	if (i < dstsize)
	{
		ft_strncat(dst, tmp_src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (i + j);
}
