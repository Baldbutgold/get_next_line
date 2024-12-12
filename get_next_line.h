/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:16:04 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/12/11 16:24:07 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strchr(char *s, int c);
char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
