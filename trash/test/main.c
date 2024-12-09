#include "get_next_line.h"

int	main()
{
	int	fd;
	ssize_t	d;
	char	*buffer;

	buffer = malloc(11);
	fd = open("test.txt", O_RDONLY);
	d = read(fd, buffer, 10);
	printf("%d", d);
}
