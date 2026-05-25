/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:17:35 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/07 17:29:49 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *s);
char	*get_stash(char **stash, ssize_t bytes_read);
int		check_reads(ssize_t bytes_read, char *buffer, char **stash);
char	*ft_strjoin(char const *s1, char const *s2);
int		to_find_endl(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*extract_line(char **stash);

#endif
