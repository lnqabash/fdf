/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:23:04 by lnqabash          #+#    #+#             */
/*   Updated: 2018/08/25 08:37:50 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	t_vm	file;

	if (argc != 2)
		ft_putendl("Error: missing argument");
	else
	{
		file.scan = argv[1];
		file.fd = open(file.scan, O_RDONLY);
		if (inferr(&file) == -1)
		{
			ft_putendl("Error");
			return (0);
		}
		mlx(&file);
	}
	return (0);
}
