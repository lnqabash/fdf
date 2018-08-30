/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:57:06 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/15 14:45:42 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*tmp_s1;
	char	*tmp_s2;
	size_t	index;

	index = 0;
	tmp_s1 = (char *)s1;
	tmp_s2 = (char *)s2;
	if (n == 0)
		return (0);
	while (tmp_s1[index] && tmp_s1[index] == tmp_s2[index]
			&& index < n - 1)
		index++;
	return ((unsigned char)tmp_s1[index] - (unsigned char)tmp_s2[index]);
}
