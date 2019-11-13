/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:19:41 by mroux             #+#    #+#             */
/*   Updated: 2019/11/13 13:50:17 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strnjoin(char *s1, char const *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	char	*ret;
	char	*str1;
	size_t	i;

	str1 = s1;
	i = 0;
	len1 = ft_strlen(s1);
	len2 = n;
	if (!(ret = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	while (i < len1)
		ret[i++] = *str1++;
	i = 0;
	while (i < len2)
		ret[len1 + i++] = *s2++;
	ret[len1 + len2] = 0;
	if (s1 != 0)
		free(s1);
	return (ret);
}

int		find_line(char *buffer, size_t buflen, size_t pos, size_t *ln)
{
	*ln = 0;
	if (buflen == 0)
		return (0);
	if (pos + *ln >= buflen)
		return (0);
	while (buffer[pos + *ln] != '\n')
	{
		if (pos + *ln == buflen)
			return (0);
		(*ln)++;
	}
	return (1);
}

char	*init(char **buffer, int fd, int *bytes_read)
{
	size_t	buff_size;
	char	*ret;

	buff_size = BUFFER_SIZE;
	if (*buffer == 0)
	{
		if (!(*buffer = (char *)malloc(buff_size * sizeof(char))))
			return (NULL);
		if ((*bytes_read = read(fd, *buffer, BUFFER_SIZE)) == -1)
			return (NULL);
	}
	if (!(ret = (char *)malloc(1 * sizeof(char))))
		return (NULL);
	return (ret);
}

int		reinit(char **buffer, size_t *pos, int *bytes_read)
{
	**buffer = 0;
	*pos = 0;
	*bytes_read = 0;
	return (0);
}
