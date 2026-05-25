/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:44:47 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/08 21:46:04 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	size_t	i;
	char	*old;

	if (!stash || !*stash || **stash == '\0')
		return (NULL);
	old = *stash;
	i = to_find_endl(old);
	line = ft_substr(old, 0, i + 1);
	if (old[i + 1] == '\0')
		new_stash = NULL;
	else
		new_stash = ft_substr(old,
				(unsigned int)(i + 1), ft_strlen(old + 1 + i));
	free(old);
	old = NULL;
	*stash = new_stash;
	return (line);
}

int	check_reads(ssize_t bytes_read, char *buffer, char **stash)
{
	if (bytes_read < 0)
	{
		free(buffer);
		free(*stash);
		*stash = NULL;
		return (0);
	}
	return (1);
}

char	*get_stash(char **stash, ssize_t bytes_read)
{
	char	*line;

	if (bytes_read == 0)
	{
		if (!*stash || (*stash)[0] == '\0')
		{
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		line = *stash;
		*stash = NULL;
		return (line);
	}
	if (to_find_endl(*stash) >= 0)
		return (extract_line(&(*stash)));
	if (!(*stash))
	{
		free(*stash);
		stash = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*tmp;
	static char		*stash;
	ssize_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (to_find_endl(stash) >= 0)
		return (extract_line(&stash));
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!check_reads(bytes_read, buffer, &stash))
			return (NULL);
		buffer[bytes_read] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
		if (to_find_endl(buffer) >= 0)
			break;
	}
	free(buffer);
	return (get_stash(&stash, bytes_read));
}
