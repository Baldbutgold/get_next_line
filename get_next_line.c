#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = 0; //must nul terminate the read results
	line = ft_strdup("");
	while (ft_strchr(buffer, '\n') == -1)
	{
		read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
	}
//	line = ft_substr(buffer, 0, ft_strchr(buffer, '\n') + 1);
	return line;
}
int	main()
{
	int	fd;
	char	*c;

	fd = open("test.txt", O_RDONLY);
	c = get_next_line(fd);
	int i = 0;
	while (i < ft_strlen(c))
	{
		printf("char : %c, value is %d\n", c[i], c[i]);
		i++;
	}
}
