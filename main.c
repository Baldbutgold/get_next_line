#include "get_next_line.h"
int	main()
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = malloc(BUFFER_SIZE + 1);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}
