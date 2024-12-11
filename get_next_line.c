/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:41:16 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/12/11 15:41:17 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	char		*re_line;
	static char	*line;
	ssize_t		r_pos;
	int			nl_pos;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	if (!line)
		return (free(buf), NULL);
	r_pos = 1;
	while (ft_strchr(line, '\n') == -1 && r_pos > 0)
	{
		r_pos = read(fd, buf, BUFFER_SIZE);
		if (r_pos == -1)
		{
			free(buf);
			free(line);
			line = NULL;
			return (NULL);
		}
		buf[r_pos] = '\0';
		temp = ft_strjoin(line, buf);
		if (!temp)
		{
			free(buf);
			free(line);
			line = NULL;
			return (NULL);
		}
		free(line);
		line = temp;
	}
	free(buf);
	if (r_pos == 0 && (!line || *line == '\0'))
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	nl_pos = ft_strchr(line, '\n');
	if (nl_pos >= 0)
	{
		re_line = ft_substr(line, 0, nl_pos + 1);
		temp = ft_substr(line, nl_pos + 1, ft_strlen(line) - nl_pos - 1);
		free(line);
		line = temp;
	}
	else
	{
		re_line = ft_strdup(line);
		free(line);
		line = NULL;
	}

	return (re_line);
}
