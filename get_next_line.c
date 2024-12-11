#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*return_line;
	static char	*line = NULL;
	ssize_t		read_pos;
	int			newline_pos;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	if (!line)
		return (free(buffer), NULL);
	read_pos = 1;
	while (ft_strchr(line, '\n') == -1 && read_pos > 0)
	{
		read_pos = read(fd, buffer, BUFFER_SIZE);
		if (read_pos == -1)
		{
			free(buffer);
			free(line);
			line = NULL;
			return (NULL);
		}
		buffer[read_pos] = '\0';
		temp = ft_strjoin(line, buffer);
		if (!temp)
		{
			free(buffer);
			free(line);
			line = NULL;
			return (NULL);
		}
		free(line);
		line = temp;
	}
	free(buffer);
	if (read_pos == 0 && (!line || *line == '\0'))
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	newline_pos = ft_strchr(line, '\n');
	if (newline_pos >= 0)
	{
		return_line = ft_substr(line, 0, newline_pos + 1);
		char *temp = ft_substr(line, newline_pos + 1, ft_strlen(line) - newline_pos - 1);
		free(line);
		line = temp;
	}
	else
	{
		return_line = ft_strdup(line);
		free(line);
		line = NULL;
	}

	return (return_line);
}

