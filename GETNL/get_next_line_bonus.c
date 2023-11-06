/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:38:47 by anporced          #+#    #+#             */
/*   Updated: 2023/11/06 12:12:11 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_stash(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	res = ft_substr(stash, i, ft_strlen(stash) - i + 1);
	free(stash);
	if (res[0] == 0)
	{
		free(res);
		res = NULL;
	}
	return (res);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	res = ft_substr(stash, 0, i);
	return (res);
}

char	*ft_stash_update(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	res = ft_substr(stash, i, ft_strlen(stash) - i + 1);
	if (!res)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	if (res[0] == 0)
	{
		free(res);
		res = NULL;
	}
	return (res);
}

char	*f_read(int fd, char *buffer, char *stash)
{
	int		r;

	r = 1;
	while (r && !ft_strchr(stash, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (r == 0)
			break ;
		buffer[r] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash[fd]), stash[fd] = NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stash[fd] = f_read(fd, buffer, stash[fd]);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_stash_update(stash[fd]);
	return (line);
}
