#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*return_line;
	static	char	*line;
	ssize_t		read_pos;
	int		newline_pos;

	return_line = NULL;;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	if (!line)
		line = ft_strdup("");
	while (ft_strchr(line, '\n') == -1 && read_pos != 0)
	{
		read_pos = read(fd, buffer, BUFFER_SIZE);
		buffer[read_pos] = '\0';
		if (buffer[0] == '\0')
			return (NULL);
		line = ft_strjoin(line, buffer);
	}
	if ((newline_pos = ft_strchr(line, '\n')) >= 0 || read_pos == 0)
	{
		if (read_pos == 0)
			return_line = ft_substr(line, 0, ft_strlen(line));
		else
		{
		return_line = ft_substr(line, 0, newline_pos + 1);
		line = line + newline_pos + 1;
		}
	}
	return (return_line);
}
