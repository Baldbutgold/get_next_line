#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*return_line;
	static	char	*line = NULL;
	ssize_t		read_pos;
	int		pos;

	return_line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	if (!line)
		line = ft_strdup("");
	if (!line)
		return (free(buffer), NULL);
	read_pos = 1;
	while (ft_strchr(line, '\n') == -1 && read_pos > 0)
	{
		read_pos = read(fd, buffer, BUFFER_SIZE);
		if (read_pos == -1) // Handle read error
		{
			free(buffer);
			free(line);
			line = NULL;
			return (NULL);
		}
		buffer[read_pos] = '\0';
		if (buffer[0] == '\0')
			return (NULL);
		char *temp = ft_strjoin(line, buffer);// no free
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
	if (ft_strchr(line, '\n') >= 0 || read_pos == 0)
	{
		pos = ft_strchr(line, '\n');
		if (read_pos == 0)
		{
			return_line = ft_substr(line, 0, ft_strlen(line));
			free(line);
			line = NULL;
		}
		else
		{
			return_line = ft_substr(line, 0, pos + 1);
			if (!return_line)
			{
				free(line);
				free(buffer);
				line = NULL;
				return (NULL);
			}
			char *temp = ft_substr(line, pos + 1, ft_strlen(line) - pos - 1);
			free(line);
			line = temp;
		}
	}
	free(buffer);
	return (return_line);
}
