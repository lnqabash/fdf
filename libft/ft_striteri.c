/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:25:37 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/13 15:44:01 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	int				index;

	i = 0;
	index = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[index] != '\0')
	{
		(*f)(i, s + index);
		i++;
		index++;
	}
}
