#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	printf("%d", ft_strchr(buffer, '\n'));
	line = ft_substr(buffer, 0, ft_strchr(buffer, '\n'));
	return line;
}
int	main()
{
	int	fd;
	char	*c;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
