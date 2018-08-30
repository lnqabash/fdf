/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:37:59 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/15 08:15:16 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	while (s1[index] && (s1[index] == s2[index]))
		index++;
	if (s1[index] != s2[index])
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}
