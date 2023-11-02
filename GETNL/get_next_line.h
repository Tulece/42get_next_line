/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:02:08 by antoine           #+#    #+#             */
/*   Updated: 2023/11/02 22:17:02 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		found_newline(char *buf);
char	*clean_stash(char *stash);
char	*extract_line(char *stash);
char	*read_file(int fd, char *stash);
char	*get_next_line(int fd);
char    *ft_strdup(char *src);

#endif