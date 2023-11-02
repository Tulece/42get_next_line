/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:02:06 by antoine           #+#    #+#             */
/*   Updated: 2023/11/02 22:13:05 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		found_newline(char *buf)
{
    int		i;

    i = 0;
    if (!buf)
        return (-1);
    while (buf[i])
    {
        if (buf[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char	*clean_stash(char *stash)
{
    int		i;
    int		j;
    char	*new_stash;

    i = 0;
    j = 0;
    if (!stash)
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    if (!(new_stash = malloc(sizeof(char) * ((ft_strlen(stash) - i) + 1))))
        return (NULL);
    i++;
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = 0;
    free(stash);
    return (new_stash);
}

char	*extract_line(char *stash)
{
    int		i;
    char	*line;

    i = 0;
    if (!stash)
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!(line = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    line[i] = 0;
    return (line);
}

char	*read_file(int fd, char *stash)
{
    int		ret;
    char	*buf;

    if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (NULL);
    ret = 1;
    while (found_newline(stash) == -1 && ret != 0)
    {
        if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[ret] = 0;
        stash = ft_strjoin(stash, buf);
    }
    free(buf);
    return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}