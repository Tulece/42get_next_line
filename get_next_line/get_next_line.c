/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:12:57 by anporced          #+#    #+#             */
/*   Updated: 2023/10/21 21:32:22 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(int fd, char *buf)
{
	int	ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	return (ret);
}

static int	append_and_return(char **line, char **str)
{
	char	*nextline;

	nextline = ft_strchr(*str, '\n');
	if (nextline)
	{
		*line = ft_substr(*str, 0, nextline - *str);
		*str = ft_strdup(nextline + 1);
		return (1);
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*str == NULL;
	char		*buf;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	ret = 1;
	while (!ft_strchr(str, '\n'))
	{
		ret = read_buffer(fd, buf);
		if (ret <= 0)
			break ;
		str = ft_strjoin(str, buf);
	}
	free(buf);
	if (!ret && !str[0])
	{
		*line = ft_strdup("");
		free(str);
		return (0);
	}
	return (append_and_return(line, &str));
}
