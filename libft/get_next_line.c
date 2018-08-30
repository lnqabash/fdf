/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 08:17:50 by lnqabash          #+#    #+#             */
/*   Updated: 2018/08/25 09:03:47 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_line(char **ptr, char **line, int fd, int read_val)
{
	char	*temp;
	int		index;

	index = 0;
	while (ptr[fd][index] != '\n' && ptr[fd][index] != '\0')
		index++;
	if (ptr[fd][index] == '\n')
	{
		*line = ft_strsub(ptr[fd], 0, index);
		temp = ft_strdup(ptr[fd] + index + 1);
		free(ptr[fd]);
		ptr[fd] = temp;
		if (ptr[fd][0] == '\0')
			ft_strdel(&ptr[fd]);
	}
	else if (ptr[fd][index] == '\0')
	{
		if (read_val == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(ptr[fd]);
		ft_strdel(&ptr[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			read_val;
	char		*ptr_copy;
	char		buffer[BUFF_SIZE + 1];
	static char	*ptr[255];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((read_val = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_val] = '\0';
		if (ptr[fd] == NULL)
			ptr[fd] = ft_strnew(1);
		ptr_copy = ft_strjoin(ptr[fd], buffer);
		free(ptr[fd]);
		ptr[fd] = ptr_copy;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_val < 0)
		return (-1);
	else if (read_val == 0 && (ptr[fd] == NULL || ptr[fd][0] == '\0'))
		return (0);
	return (read_line(ptr, line, fd, read_val));
}
