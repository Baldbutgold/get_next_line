#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer;

	return buffer;
}
int	main()
{
	int	fd;
	char	*c;

	fd = open("test.txt", O_RDONLY);
	read(fd, c, 1);
	printf("%d\n", fd);
	printf("%c", c[0]);
}
