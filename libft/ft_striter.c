/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:18:57 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/14 10:30:45 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		index;

	index = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[index])
	{
		(*f)(s + index);
		index++;
	}
}
