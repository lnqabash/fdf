/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:19:45 by lnqabash          #+#    #+#             */
/*   Updated: 2018/08/25 10:29:33 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		spect_limit(char *str, int j, int contra)
{
	int		index;
	int		count;
	int		tmp;

	index = 0;
	count = 0;
	tmp = 0;
	while (str[index])
	{
		if (ft_isdigit(str[index]) == 0)
		{
			if (str[index] != ' ')
				return (-1);
			count = 0;
		}
		else
		{
			if (count == 0)
				tmp++;
			count++;
		}
		index++;
	}
	return (valu(j, count, contra));
}

int		valu(int x, int y, int z)
{
	if (x == 0)
		return (0);
	else if (z == y)
		return (z);
	else
		return (-1);
}

int		get_limit(t_vm *infer)
{
	char	*line;
	int		count;

	line = NULL;
	infer->limit = 0;
	infer->nneka = 0;
	while ((count = get_next_line(infer->fd, &line)) > 0)
	{
		if (tab_axes(infer, line) == -1)
			return (-1);
	}
	infer->map = ft_memalloc(sizeof(int*) * infer->limit);
	close(infer->fd);
	infer->fd = open(infer->scan, O_RDONLY);
	return (0);
}

int		tab_axes(t_vm *infer, char *line)
{
	int		index;
	char	**ptr;

	index = 0;
	ptr = ft_strsplit(line, ' ');
	while (ptr[index])
	{
		free(ptr[index]);
		index++;
	}
	if (infer->limit == 0)
		infer->nneka = index;
	else
	{
		if (index != infer->nneka)
			return (-1);
	}
	free(line);
	free(ptr);
	infer->limit++;
	return (0);
}

int		inferr(t_vm *parse)
{
	char	*line;
	char	**ptr;
	int		ptrxy[3];

	ptrxy[1] = 0;
	if (get_limit(parse) == -1)
		return (-1);
	while ((ptrxy[2] = get_next_line(parse->fd, &line)) > 0)
	{
		ptrxy[0] = 0;
		ptr = ft_strsplit(line, ' ');
		parse->map[ptrxy[1]] = ft_memalloc(sizeof(int) * parse->nneka);
		while (ptr[ptrxy[0]] != NULL)
		{
			parse->map[ptrxy[1]][ptrxy[0]] = ft_atoi(ptr[ptrxy[0]]);
			free(ptr[ptrxy[0]]);
			ptrxy[0]++;
		}
		free(ptr);
		ptrxy[1]++;
	}
	if (ptrxy[2] == -1)
		return (-1);
	else
		return (0);
}
