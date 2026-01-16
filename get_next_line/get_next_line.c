/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:37:15 by csilva            #+#    #+#             */
/*   Updated: 2026/01/15 14:03:35 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	__ssize_t	byte_r;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > __FD_SETSIZE)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] == 0)
		{
			byte_r = read(fd, buffer, BUFFER_SIZE);
			if (byte_r == -1)
				return (NULL);
			if (byte_r == 0)
				return (line);
		}
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		updt_buffer(buffer);
		if (ft_strchr(line, '\n'))
			return (line);
	}
}
