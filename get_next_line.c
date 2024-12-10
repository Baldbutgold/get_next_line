#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*return_line;
	static	char	*line;
	ssize_t		read_pos;
	int		newline_pos;

	return_line = NULL;
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
		if (!line)
			return (free(line), free(buffer), NULL);
	}
	if (ft_strchr(line, '\n') >= 0 || read_pos == 0)
	{
		newline_pos = ft_strchr(line, '\n');
		if (read_pos == 0)
			return_line = ft_substr(line, 0, ft_strlen(line));
		else
		{
			return_line = ft_substr(line, 0, newline_pos + 1);
			if (!return_line)
				return (free(return_line), free(line), free(buffer), NULL);
			//line = ft_substr(line + newline_pos + 1, ft_strlen(line));
			line = line + newline_pos + 1;
		}
	}
	free(buffer);
	return (return_line);
}
// free when in problem
// test if malloc a string twice does it free correctly
// free if read gives -1
