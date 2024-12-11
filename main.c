#include "get_next_line.h"
int	main()
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	free(line);
}
