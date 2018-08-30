/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:04:38 by lnqabash          #+#    #+#             */
/*   Updated: 2018/06/15 08:11:36 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	long	res;
	int		index;

	index = 0;
	res = 0;
	while ((str[index] >= '\t' && str[index] <= '\r') || str[index] == 32)
		index++;
	if (str[index] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] && ft_isdigit(str[index]))
	{
		res = (res * 10) + (str[index] - '0');
		index++;
	}
	return (sign * res);
}
