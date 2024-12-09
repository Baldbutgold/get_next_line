#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	ssize_t		read_len;
	
	buffer = malloc(BUFFER_SIZE + 1);
	read_len = read(fd, buffer, BUFFER_SIZE);
	buffer[read_len] = '\0';
	line = ft_strdup("");
	if (ft_strchr(buffer, '\n') >= 0)
		printf("\\n exists\n");
	else
	{
		while (ft_strchr(line, '\n' == -1))
		{
			read(fd, buffer, BUFFER_SIZE);
			line = ft_strjoin(line, buffer);
		}
		printf("\\n doesn't exist\n");
	}
	printf("this is line %s", line);
	return ("nothing");
}
