#include "get_next_line.h"
int	main()
{
	int	fd;
	char	*line;

	fd = open("big_line_no_nl", O_RDONLY);
	line = get_next_line(fd);
	while(line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	free(line);
}
