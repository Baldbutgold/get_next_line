#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	char	*c;

	fd = open("test.txt", O_RDONLY);
	read(fd, c, 1);
	printf("%d\n", fd);
	printf("%c", c[0]);
}
