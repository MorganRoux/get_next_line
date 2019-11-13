/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:06:08 by mroux             #+#    #+#             */
/*   Updated: 2019/11/13 13:51:47 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*buffer = 0;
	static size_t	pos = 0;
	static int		bytes_read = 0;
	size_t			ln;

	ln = 0;
	if (line == 0 || (*line = init(&buffer, fd, &bytes_read)) == NULL)
		return (-1);
	while (find_line(buffer, bytes_read, pos, &ln) == 0)
	{
		*line = ft_strnjoin(*line, &buffer[pos], ln);
		pos = 0;
		if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) <= 0)
		{
			reinit(&buffer, &pos, &bytes_read);
			return (bytes_read);
		}
	}
	*line = ft_strnjoin(*line, &buffer[pos], ln);
	pos += ln + 1;
	return (1);
}
