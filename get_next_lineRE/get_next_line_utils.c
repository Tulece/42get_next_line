/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:34:07 by anporced          #+#    #+#             */
/*   Updated: 2023/10/21 21:54:21 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	int		i;
	int		j;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && i < len)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;
	char		*tmp;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (ptr == NULL)
		return (NULL);
	ret = 1;
	while (ret != 0 && ft_strchr(str, '\n') == NULL)
	{
		ret = read(fd, ptr, BUFFER_SIZE);
		if (ret == -1)
		{
			free(ptr);
			return (NULL);
		}
		ptr[ret] = '\0';
		tmp = ft_strjoin(str, ptr);
		free(str);
		str = tmp;
	}
	free(ptr);
	return (ft_substr(str, 0, ft_strlen(str)));
}

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s\n", line);
			free(line);
		}
		close(fd);
	}
	return (0);
}
