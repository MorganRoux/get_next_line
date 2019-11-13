/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:35:37 by mroux             #+#    #+#             */
/*   Updated: 2019/11/13 13:47:45 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		find_line(char *buffer, size_t buflen, size_t pos, size_t *ln);
char	*ft_strnjoin(char *s1, char const *s2, size_t n);
char	*init(char **buffer, int fd, int *bytes_read);
int		reinit(char **buffer, size_t *pos, int *bytes_read);
void	ft_putstr_fd(char *s, int fd);

#endif
